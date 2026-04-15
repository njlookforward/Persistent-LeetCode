/**
 * @brief 实现自己版本的shared_ptr，重点关注以下几个函数，因为是
 * 1. 共享所有权，atomic<int> 引用计数是堆空间对象，而且是原子变量
 * 2. 拷贝语义：是浅拷贝，指向同一个对象和计数器的指针
 * 3. 移动语义
 * 4. 析构函数：需要判断是否引用计数为零
 * 5. 最基础的解引用*和->箭头访问运算符
 */
#include <atomic>
#include <stdexcept>

// Bug5 Fix: 头文件中不应使用 using namespace std，会污染所有包含此头文件的翻译单元

template <typename T>
class MyShared_ptr {
public:
    // Bug1 Fix: 初始化列表多个成员间用逗号分隔，不能写两个冒号
    explicit MyShared_ptr(T *obj = nullptr)
    : obj_(obj)
    , refCounter_(obj == nullptr ? nullptr : (new std::atomic<int>(1))) {}

    ~MyShared_ptr() {
        release();
    }

    // 拷贝语义
    MyShared_ptr(const MyShared_ptr &rhs)
    : obj_(rhs.obj_)
    , refCounter_(rhs.refCounter_) {
        // Bug2 Fix: rhs 可能是空的 shared_ptr（refCounter_ == nullptr），需判断再自增
        if(refCounter_) {
            ++*refCounter_;
        }
    }

    MyShared_ptr &operator=(const MyShared_ptr &rhs) {
        if(this != &rhs) {
            release();
            obj_ = rhs.obj_;
            refCounter_ = rhs.refCounter_;
            // Bug2 Fix: 同拷贝构造，需判断再自增
            if(refCounter_) {
                ++*refCounter_;
            }
        }

        return *this;
    }

    // 移动语义
    MyShared_ptr(MyShared_ptr &&rhs)
    : obj_(rhs.obj_)
    , refCounter_(rhs.refCounter_) {
        rhs.obj_ = nullptr;
        rhs.refCounter_ = nullptr;
    }

    MyShared_ptr &operator=(MyShared_ptr &&rhs) {
        if(this != &rhs) {
            release();
            obj_ = rhs.obj_;
            refCounter_ = rhs.refCounter_;

            rhs.obj_ = nullptr;
            rhs.refCounter_ = nullptr;
        }

        return *this;
    }

    T &operator*() {
        if(!obj_) {
            throw std::runtime_error("MyShared_ptr is nullptr");
        }

        return *obj_;
    }

    T &operator*() const {
        if(!obj_) {
            throw std::runtime_error("MyShared_ptr is nullptr");
        }

        return *obj_;
    }

    T *operator->() {
        if(!obj_) {
            throw std::runtime_error("MyShared_ptr is nullptr");
        }

        return obj_;
    }

    T *operator->() const {
        if(!obj_) {
            throw std::runtime_error("MyShared_ptr is nullptr");
        }

        return obj_;
    }

    T *get() {
        return obj_;
    }

    // Bug4 Fix: 补充 const 版本的 get()
    T *get() const {
        return obj_;
    }

    /**
     * Bug3 Fix: 原实现的问题：
     * 1. 引用计数减为 0 时，delete obj_ 后忘记 delete refCounter_，造成内存泄漏
     * 2. 引用计数不为 0 时（其他人仍持有），obj_ 被置 nullptr 导致其他持有者悬空指针
     * 3. 有新对象时直接 *refCounter_ = 1，覆盖了其他持有者的共享计数，造成数据损坏
     * 正确做法：复用 release() 释放旧资源，再根据 newObj 重新分配
     */
    void reset(T *newObj = nullptr) {
        release();  // 释放当前持有的资源（release 内部已将成员置 nullptr）

        if(newObj) {
            obj_ = newObj;
            refCounter_ = new std::atomic<int>(1);
        }
        // 若 newObj == nullptr，release() 已将两个成员置为 nullptr，无需额外操作
    }

private:
    void release() {
        // RAII思想去检查是否需要释放资源
        if(refCounter_ && --*refCounter_ == 0) {
            delete obj_;
            delete refCounter_;
        }
        obj_ = nullptr;
        refCounter_ = nullptr;
    }

private:
    T *obj_;                        // 被管理的对象
    std::atomic<int> *refCounter_;  // 共享的引用计数
};