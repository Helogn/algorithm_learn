/*
121. 买卖股票的最佳时机
简单
相关标签
相关企业
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
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
        
        int minV = std::min((prices[size - 2] - prices[size - 1]),0);
        for(int i = size - 1; i--)
        {
            minV = prices[i] - 
        }


        vector<int> max_money(size);
        int minus = prices[size-2] - prices[size-1];
        max_money[size - 1] = (0 > minus)? minus:0;
        int lower = prices[size - 1];
        int res = 0;
        
        for (int i = size-2; i>=0; i--)
        {
            lower = (lower > prices[i+1]) ? prices[i+1] : lower;
            max_money[i] = lower;
            int diff = prices[i+1] - lower;
            res = (res > diff) ? res : diff;
        }
        
        return res;

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
