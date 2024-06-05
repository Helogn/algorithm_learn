/*
15. 三数之和
中等
提示
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
 */

#include<vector>
#include<iostream>
#include<algorithm>
#include"com.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int left = 0, right = size - 1;
        
        

        return res;
    }
};


int main()
{
    vector<int> vec1 = {1,3,5,-1,-3,-2,-5};
    Solution res = Solution();
    vector<vector<int>> new_res = res.threeSum(vec1);
    printvec(new_res[0]);
    
    return 0;
}