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
        // loop
        for (int i = 0; i < size - 2; i++)
        {
            while (i > 0 && i < size - 2 && nums[i - 1] == nums[i]) i++; // 忘记判断i
            int left = i + 1, right = size - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0)
                {
                    vector<int> one_res = {nums[i], nums[left], nums[right]};
                    // cout << i <<" "<<left <<" "<< right<<endl;
                    // cout << nums[i] <<" "<<nums[left] <<" "<< nums[right]<<endl <<"----------------------"<<endl;
                    res.push_back(one_res);
                    while(left + 1< right && nums[left] == nums[left + 1]) left++;
                    while(left < right - 1 && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
                else if (sum > 0) right--;
                else left++;
            }
        }
        return res;
    }
};


int main()
{
    vector<int> vec1 = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution res = Solution();
    vector<vector<int>> new_res = res.threeSum(vec1);
    printvec(new_res[0]);
    
    return 0;
}