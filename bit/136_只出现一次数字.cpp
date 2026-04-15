#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::cout, std::cin, std::endl;
using std::string;
using std::vector;
using std::unordered_map;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // 这道题考察的是位运算，1 ^ 1 = 0; 0 ^ 1 = 1
        int res = 0;
        for (auto & num : nums)
        {
            res ^= num;
        }
        return res;
    }

    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> u_map;
        for(auto num : nums)
        {
            u_map[num]++;
        }
        for (auto & elem : u_map)
        {
            if(elem.second == 1)
                return elem.first;
        }
        
        return 0;
    }
};

void test1() {
    
}

int main(int argc, char *argv[]) {
    test1();

    return 0;
}