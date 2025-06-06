#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
using std::cout; using std::endl;

#include <vector>
using std::vector;

inline void display(const vector<vector<int>> &dp) {
    for(int i = 0; i < dp.size(); i++) {
        for(int j = 0; j < dp[0].size(); j++) 
            cout << "[" << i << "," << j << "]: "
                 << dp[i][j] << " ";
        cout << endl;
    }
}

#endif