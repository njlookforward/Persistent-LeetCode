#include <string>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        array<int, 26> alphaCnt = {};
        for (auto ch : s)
        {
            ++alphaCnt[ch - 'a'];
        }
        for (auto &i : t)
        {
            --alphaCnt[i - 'a'];
        }
        auto resit = find_if(alphaCnt.cbegin(), alphaCnt.cend(),
            [](int num) { return num != 0; });
        
        return resit == alphaCnt.cend();
    }
};