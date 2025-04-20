#ifndef EXERCISE_HPP
#define EXERCISE_HPP

#include <iostream>
using std::cout; using std::endl;

template <typename Container>
inline void display(const Container &c) {
    for (auto &entry : c)
    {
        cout << entry << " ";
    }
    cout << endl;
}

// 模板特例化
template <>
inline void display(const vector<string> &chessboard) {
    for(const string &line : chessboard) {
        for(char ch : line) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
#endif