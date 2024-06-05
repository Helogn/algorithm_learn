#include<iostream>
#include<vector>
#include<algorithm>
#include "com.h"

// using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size);
        vector<int> left(size);
        vector<int> right(size);

        for (int i = 0; i < size; i++)
        {
            if(i == 0)
            {
                left[i] = 1;
                right[size - 1] = 1;
            }
            else
            {
                left[i] = left[i-1] * nums[i-1];
                right[size - 1 - i] = right[size - i] * nums[size - i];
            }
        }

        for (int i = 0; i < size; i++)
        {
            res[i] = left[i] * right[i];
        }
        return res;
        
    }
};

int main()
{

    vector<int> vec = {4,2,0,4,5};
    Solution res = Solution();
    vector<int> resVec = res.productExceptSelf(vec);

    printvec(resVec);
    // std::cout << max << std::endl;
    return 0;

}

