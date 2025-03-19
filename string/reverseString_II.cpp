#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k)
    {
        int i = 0;
        while (i < s.size())
        {
            auto bgit = s.begin() + i;
            auto edit = i + k <= s.size() ? bgit + k : s.end();
            reverse(bgit, edit);
            i += 2 * k;    
        }
        return s;
    }
};