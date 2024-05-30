/*
121. 买卖股票的最佳时机 
medium
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include "com.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        size_t size = prices.size();
        if (size<=1) return 0;
        
        int min_price = prices[0];
        int max_value = 0;
        for(int i = 1; i < size; i++)
        {
            max_value = max(max_value, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }

        return max_value;

    }
};

int main()
{
    // 指针从后循环
    vector<int> vec = {1,3,5,7,3,4,65,7,8,32,1,2,3,4,2,4};

    Solution res = Solution();
    int max = res.maxProfit(vec);

    printvec(vec);
    std::cout << max << std::endl;
    return 0;

}
