/*
给你一个整数数组 citations ，
其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。
计算并返回该研究者的 h 指数。

根据维基百科上 h 指数的定义：h 代表“高引用次数” ，
一名科研人员的 h 指数 是指他（她）至少发表了 h 篇论文，
并且 至少 有 h 篇论文被引用次数大于等于 h 。
如果 h 有多种可能的值，h 指数 是其中最大的那个。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include "com.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if (citations.empty()) return 0;

        std::sort(citations.begin(), citations.end(), std::greater<int>());
        int res = 0;
        for(int i = 0; i< size; i++)
        {
            if(i < citations[i])
            {
                res++;
            }    
            else
            {
                break;
            }

        }
        return res;
    }
};

int main()
{
    // 指针从后循环
    vector<int> vec = {1,2,4,5,7,8,4,2,3,4,5};

    Solution res = Solution();
    int max = res.hIndex(vec);
    printvec(vec);
    std::cout << max << std::endl;
    return 0;

}
