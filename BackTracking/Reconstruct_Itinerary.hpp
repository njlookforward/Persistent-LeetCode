#ifndef RECONSTRUCT_ITINERARY_HPP
#define RECONSTRUCT_ITINERARY_HPP

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <unordered_map>
using std::unordered_map;

#include <map>
using std::map;

#include <utility>
using std::pair;

/**
 * @details: 关键点：1. 使用数据结构unordered_map<起点，map<终点，待使用次数>>
 * 2. 使用回溯算法
 * 3. 使用vector<string>记录最终结果
*/

/**
 * @param 使用unordered_map<string, map<string,int>>。由于飞机票是<起点，终点>一对数据，因此采用
 * unordered_map保存键值对数据，作为回溯遍历的容器；其中key是起点，value应该是一个容器保存终点的序列
 * 由于在回溯遍历过程中需要记录已经经过的飞机站，不能删除容器，否则迭代器会失效，因此采用map<string,int>
 * 记录是否已经遍历过，由于题目要求按照字典序进行遍历，因此采用map
 * 回溯问题处理的都是一个集合，然后思考如何在这个集合中做回溯。
*/

// 我自己的解法超出了时间限制，可恶啊
class Solution {
public:
    void buildTargets(unordered_map<string, map<string, int>> &targets, vector<vector<string>> &tickets);
    void backTracking(unordered_map<string, map<string, int>> &targets, string startAirport,
                      vector<string> &path, vector<string> &result, int end);
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        unordered_map<string, map<string, int>> targets;
        buildTargets(targets, tickets);
        vector<string> path;
        vector<string> result;
        path.push_back("JFK");
        backTracking(targets, "JFK", path, result, tickets.size() + 1);
        return result;
    }
};

inline void Solution::buildTargets(unordered_map<string, map<string, int>> &targets, 
                            vector<vector<string>> &tickets) {
    for (auto &ticket : tickets)
    {
        string depart = ticket[0];  // 起点
        string arrival = ticket[1]; // 终点
        ++targets[depart][arrival];
    }
}

inline void Solution::backTracking(unordered_map<string, map<string, int>> &targets,
        string startAirport, vector<string> &path, vector<string> &result, int end) {
    if(result.size() == end) return;
    if(path.size() == end) {
        // BUG: 自作聪明，出事了，因为递归返回到上一层后，还需要弹出pop_back，因此只能拷贝赋值
        result = path;
        return;
    }
    // 每次递归加入的都是新的终点站
    // BUG: arrivalAirports中second的变化情况没有反应到targets中，必须使用引用才能搞定
    auto &arrivalAirports = targets[startAirport];
    for(auto arrival = arrivalAirports.begin(); arrival != arrivalAirports.end(); ++arrival) {
        if(arrival->second == 0) continue;
        path.push_back(arrival->first);
        --arrival->second;
        backTracking(targets, arrival->first, path, result, end);    // 新加入的终点，再一次递归时成为新的起点
        ++arrival->second;
        path.pop_back();
    }
    return;
}

// 我的方法的确是做了一些无用功，如果找到结果，在递归的过程中，应该直接返回
// 这种方法也超时了，看评论说应该使用深度优先遍历，以后学完之后再进行修改吧
// TODO
class Solution_carl {
public:
    bool backTracking(unordered_map<string, map<string,int>> &targets, vector<string> &result, int ticketNum) {
        if(result.size() == ticketNum + 1) {
            return true;
        }
        auto &arrivals = targets[result[result.size()-1]];
        // key:必须使用引用形式，才能改变targets中的对应的map中的second
        for (pair<const string, int> &arrival : arrivals)
        {
            if(arrival.second > 0) {
                result.push_back(arrival.first);
                arrival.second--;
                if(backTracking(targets, result, ticketNum)) return true;
                arrival.second++;
                result.pop_back();
            }
        }
        return false;   
    }
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        unordered_map<string, map<string,int>> targets;
        for(const vector<string> &ticket : tickets) {
            targets[ticket[0]][ticket[1]]++;
        }
        vector<string> result;
        result.push_back("JFK");
        backTracking(targets, result, tickets.size());
        return result;
    }
};

#endif