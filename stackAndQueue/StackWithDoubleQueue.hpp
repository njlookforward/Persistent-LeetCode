#ifndef STACKWITHDOUBLEQUEUE_HPP
#define STACKWITHDOUBLEQUEUE_HPP

#include <queue>

class MyStack {
public:
    MyStack() = default;
    ~MyStack() = default;

    void push(int x);
    int pop();
    int top() const;
    bool empty() const;

private:
    std::queue<int> _queue1;   // input queue
    std::queue<int> _queue2;  // output queue
};

inline void MyStack::push(int x)
{
    _queue2.empty() ? _queue1.push(x)
                    : _queue2.push(x);
}

inline int MyStack::pop()
{
    auto &popQue = _queue2.empty() ? _queue1 : _queue2;
    auto &pushQue = _queue2.empty() ? _queue2 : _queue1;

    while (popQue.size() != 1)
    {
        pushQue.push(popQue.front());
        popQue.pop();
    }
    
    int ret = popQue.front();
    popQue.pop();
    return ret;
}

inline int MyStack::top() const
{
    auto &validQue = _queue2.empty() ? _queue1 : _queue2;
    return validQue.back();
}

inline bool MyStack::empty() const
{
    return _queue1.empty() && _queue2.empty();
}

#endif