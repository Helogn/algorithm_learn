#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();
        int left = 0, right = size - 1;
        while(left < right)
        {
            int sum = nums[left] + nums[right];
            int mid = left + 1;
            while(mid < right)
            {
                int thr_sum = sum + nums[mid];

                if (thr_sum > 0) break;
                else if(thr_sum == 0)
                {
                    vector<int> rres{nums[left], nums[right], nums[mid]};
                    res.push_back(rres);
                    while(nums[left] == nums[left+1] && left < right) left++;
                    while(nums[right] == nums[right-1] && left < right) right--;
                    break;
                }
                else
                {
                    ++mid;
                }
            }
            if (sum <= 0 ) ++left;
            else if (sum > 0 ) --right;
        }
        return res;    
    }
};

int main()
{
    Solution a = Solution();
    vector<int> in1 = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = a.threeSum(in1);

    return 0;
}

// ------------------------------------
// official solution
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> res;
//         int size = nums.size();
//         for(int i = 0; i < size - 2; ++i) {
//             // Skip duplicate elements
//             if (i > 0 && nums[i] == nums[i - 1]) continue;
//             int left = i + 1, right = size - 1;
//             while(left < right) {
//                 int sum = nums[i] + nums[left] + nums[right];
//                 if (sum < 0) {
//                     ++left;
//                 } else if(sum > 0) {
//                     --right;
//                 } else {
//                     vector<int> rres{nums[i], nums[left], nums[right]};
//                     res.push_back(rres);
//                     // Skip duplicates for left and right
//                     while (left < right && nums[left] == nums[left + 1]) ++left;
//                     while (left < right && nums[right] == nums[right - 1]) --right;
//                     ++left;
//                     --right;
//                 }
//             }
//         }
//         return res;    
//     }
// };

