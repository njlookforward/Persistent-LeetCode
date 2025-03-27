#ifndef QUEUEWITHSTACK_HPP
#define QUEUEWITHSTACK_HPP

#include <stack>
// 由于题目规定，所有的pop() and peek() is valid, no needn't to judge
// #include <stdexcept>

class MyQueue {
public:
    MyQueue() = default;
    ~MyQueue() = default;

    void push(int x) {  _stackin.push(x); }
    int pop();
    int peek();
    bool empty() const;

private:
    void checkout();

    std::stack<int> _stackin;   // input stack
    std::stack<int> _stackout;  // output stack
};

inline int MyQueue::pop()
{
    checkout();
    int ret = _stackout.top();
    _stackout.pop();
    return ret;
}

inline int MyQueue::peek()
{
    checkout();
    return _stackout.top();
}

inline bool MyQueue::empty() const
{
    return _stackin.empty() && _stackout.empty();
}

inline void MyQueue::checkout()
{
    if(_stackout.empty())
    {
        while (!_stackin.empty())
        {
            _stackout.push(_stackin.top());
            _stackin.pop();
        }
    }
}

#endif  /* QUEUEWITHSTACK_HPP */