#ifndef QUEUE_RECONSTRUCTION_BY_HEIGHT
#define QUEUE_RECONSTRUCTION_BY_HEIGHT

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <algorithm>
using std::sort;

#include <iterator>
using std::advance;

class Solution {
public:
    /// @bug 编译出错，因为逻辑没有写完全，忘记写else return false; 
    /// @bug sort中的第三个比较函数参数应该是可调用对象，普通函数指针，或者是静态成员函数，或者是函数对象
    /// 或者是lambda表达式，不能是成员函数，因为成员函数需要使用对象实例才能够调用，因此需要改为静态成员函数
    static bool compare(const vector<int> &lhs, const vector<int> &rhs) {
        if(lhs[0] == rhs[0]) return lhs[1] < rhs[1];
        return lhs[0] > rhs[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(people.begin(), people.end(), compare);
        list<vector<int>> queue;
        for(int i = 0; i < people.size(); ++i) {
            int position = people[i][1];
            auto iter = queue.begin();
            advance(iter, position);
            queue.insert(iter, people[i]);
        }
        return vector<vector<int>>(queue.cbegin(), queue.cend());
    }
};


#endif