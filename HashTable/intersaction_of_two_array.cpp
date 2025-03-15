#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersaction(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result_set,
                           num_set(nums1.cbegin(), nums1.cend());
        for (int num : nums2)
        {
            if(num_set.find(num) != num_set.cend())
                result_set.insert(num);
        }
        return vector<int>(result_set.cbegin(), result_set.cend());
    }
};