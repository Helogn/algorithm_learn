/*
121. 买卖股票的最佳时机 
medium
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候最多只能持有一股股票。
你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include "com.h"
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        size_t size = prices.size();
        if (size<=1) return 0;
        
        int sum_value = 0, min_price = prices[0], max_price = prices[0];
        for(int i = 1; i < size; i++)
        {
            if(i == size - 1)
            {
                if(prices[i] > max_price)
                {
                    sum_value += prices[i] - min_price;
                }
                else
                {
                    sum_value += max_price-min_price;
                }
                return sum_value;

            }

            if(max_price > prices[i])
            {
                sum_value += max_price - min_price;
                min_price = prices[i];
            }
            max_price = prices[i];
            
        }

        return sum_value;

    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t size = prices.size();
        int money = 0;
        for (int i = 1; i< size; i++)
        {
            int minus = prices[i] - prices[i-1];
            if(minus > 0) money += minus;
            
        }
        return money;
    }
};


int main()
{
    // 指针从后循环
    vector<int> vec = {1,2,3,4,5};

    Solution res = Solution();
    int max = res.maxProfit(vec);

    printvec(vec);
    std::cout << max << std::endl;
    return 0;

}
