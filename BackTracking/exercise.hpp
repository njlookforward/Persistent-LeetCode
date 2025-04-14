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

#endif