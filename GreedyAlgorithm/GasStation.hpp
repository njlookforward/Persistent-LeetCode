#ifndef GAS_STATION_HPP
#define GAS_STATION_HPP

#include <vector>
using std::vector;

class Solution_greedy {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int curSum = 0;
        int totalSum = 0;
        int startIdx = 0;
        for(int i = 0; i < gas.size(); ++i) {
            curSum += (gas[i] - cost[i]);
            totalSum += (gas[i] - cost[i]);
            if(curSum < 0) {
                startIdx = i + 1;
                curSum = 0;
            }
        }
        if(totalSum < 0) return -1;
        else return startIdx;
    }
};

/**
 * @bug gas[2,3,4] cost[3,4,3]出现问题，我的输出是2，正确答案是-1
*/

class Solution_violent {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        for(int i = 0; i < gas.size(); ++i) {
            int stationSum = gas.size();
            int gasSum = 0;
            int curStaion = i;
            while (stationSum--)
            {
                gasSum += (gas[curStaion] - cost[curStaion]);
                if(gasSum < 0) break;
                curStaion = (curStaion + 1) % (gas.size());
            }
            // Bug: staionSum != 0 是错的，5次while循环结束时staionSum == -1了
            // Bug: 如果是在最后一个元素gasSum变为负数，也是无效的
            if(stationSum >= 0) continue;
            else return i;
        }
        return -1;
    }
};

class Solution_carl_violence {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        for(int i = 0; i < gas.size(); ++i) {
            int rest = gas[i] - cost[i];
            int index = (i + 1) % gas.size();
            while (rest >= 0 && index != i)
            {
                 rest += (gas[index] - cost[index]);
                 index = (index + 1) % gas.size();
            }
            if(rest >= 0 && index == i) return i;
        }
        return -1;
    }
};

#endif