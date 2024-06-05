
#include<iostream>
#include<vector>
#include<algorithm>
#include "com.h"


/*
此解决方案采用了一种贪心策略，每一步都高效地计算出可达到的最远点，
并且仅在必要时增加跳跃计数，从而得到最优解。
该算法的时间复杂度为O(n)，空间复杂度为O(1)，对于大数据集也非常高效。
*/


class Solution {
public:
    int jump(vector<int>& nums) {
        
        int size = nums.size();
        if(size == 1) return 0;

        int max_len = 0;
        int old_len = 0;
        int steps = 1;
        for(int i = 0; i < size; i++)
        {
            if (max_len >= size-1) return steps;
            if (i > old_len) 
            {
                steps++;
                old_len = max_len;
            }
            max_len = max(max_len, i + nums[i]);
        }
        return steps;
    }
};

int main()
{
    // 指针从后循环
    vector<int> vec = {2,3,1,1,4};

    Solution res = Solution();
    int max = res.jump(vec);

    printvec(vec);
    std::cout << max << std::endl;
    return 0;

}

