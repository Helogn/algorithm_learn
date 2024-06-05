/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
计算按此排列的柱子，下雨之后能接多少雨水。
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include "com.h"

class Solution {
public:
    int trap(vector<int>& height) {

    }
};

int main()
{
    // 指针从后循环
    vector<int> vec =  {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution res = Solution();
    int water_count = res.trap(vec);

    printvec(vec);
    std::cout << water_count << std::endl;
    return 0;

}
