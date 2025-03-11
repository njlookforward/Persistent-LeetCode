#include <vector>
using namespace std;

// 使用双指针法移除元素的原理是，快指针用来寻找不是目标值的值，慢指针从头开始填充数列，慢指针只会
// 被不是目标值的快指针赋值，对于目标值快指针会跳过去
class Solution {
public:
     int removeElement(vector<int> &ivec, int val) {
        // 因为需要将不是目标值的元素数量返回，因此需要定义局部变量
        int slower = 0;
        for(int faster = 0; faster < ivec.size(); ++faster)
        {
            if(ivec[faster] != val)
                ivec[slower++] = ivec[faster];
        }
        return slower;
    }
};