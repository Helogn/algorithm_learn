/*
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。


*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {

        int size = s.size();
        string res;
        
        int srt = 0;
        int end = 0;
        bool con1 = false;
        // std::reverse(str.begin(), str.end());
        for (int i = size -1; i > 0; i++)
        {
            if(s[i] != ' ')
            {
                if(con1 = false)
                {
                    end = i;
                    con1 = true;
                }
            }    
            else
            {
                if(con1 == true)
                {
                    srt = i;
                    con1 = false;
                    res += s.substr(srt, end-srt);
                }
                else
                {
                    if(((i-1)>0) && (s[i-1] != ' '))
                    res += ' ';
                }

            }
        }

        return res;
    }
};


/*
class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        string res;
        
        int start = size - 1; // 修改变量名以避免混淆
        int end = size;
        bool hasWord = false;
        
        // 处理末尾可能的空格
        while (start >= 0 && s[start] == ' ') start--;
        
        for (int i = start; i >= 0; --i) {
            if (s[i] == ' ') {
                if (hasWord) { // 发现单词结束
                    res += s.substr(i + 1, end - (i + 1)); // 添加单词到结果
                    end = i; // 更新单词结束位置
                    if (i > 0 && s[i - 1] != ' ') res += ' '; // 如果不是连续空格，添加一个空格
                    hasWord = false;
                }
            } else {
                hasWord = true; // 遇到字符，标记有单词
                if (i == 0) { // 处理字符串开头的单词
                    res += s.substr(i, end - i);
                }
            }
        }
        
        return res;
    }
};
*/


int main()
{
    // 指针从后循环
    string str1 = "my name is hejiang ";

    Solution res = Solution();
    string new_str = res.reverseWords(str1);
    std::cout << new_str << std::endl;
    return 0;

}


