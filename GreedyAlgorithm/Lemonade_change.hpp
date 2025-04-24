#ifndef LEMONADE_CHANGE_HPP
#define LEMONADE_CHANGE_HPP

#include <vector>
using std::vector;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        if(bills.size() == 1 && bills[0] != 5) return false;
        int fiveCnt = 0,
            tenCnt = 0;
        // 应该用范围for
        for(int bill : bills) {
            switch (bill)
            {
            case 5:
                ++fiveCnt;    
                break;
            case 10:
                if(fiveCnt == 0) return false;
                --fiveCnt;
                ++tenCnt;
                break;
            case 20:
                if(tenCnt > 0 && fiveCnt > 0) {
                    --tenCnt;
                    --fiveCnt;
                    break;
                } else if(fiveCnt >= 3) {
                    fiveCnt -= 3;
                    break;
                } else
                    return false;
            }
        }
        return true;
    }
};


#endif