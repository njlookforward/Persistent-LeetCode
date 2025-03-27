#ifndef STACKWITHSINGLEQUEUE_HPP
#define STACKWITHSINGLEQUEUE_HPP

#include <queue>

class MyStack {
public:
    MyStack() = default;
    ~MyStack() = default;

    void push(int x)    {  _queue.push(x); }
    int pop();
    int top() const     {   return _queue.back();   }
    bool empty() const  {   return _queue.empty();  }

private:
    std::queue<int> _queue;
};

inline int MyStack::pop()
{
    for(int i = 0, cnt = _queue.size() - 1; i < cnt; ++i)
    {
        _queue.push(_queue.front());
        _queue.pop();
    }

    int res = _queue.front();
    _queue.pop();
    return res;
}

#endif