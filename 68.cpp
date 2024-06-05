/*
68. 文本左右对齐
给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

注意:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于 maxWidth。
输入单词数组 words 至少包含一个单词。
 

示例 1:

输入: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
示例 2:

输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例 3:

输入:words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/


class Solution {
public:
    int ind = 0;
    int poor_str_num = 0;
    vector<string> poor;
    vector<string> res; // save return value 
    int remain_space;

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        remain_space = maxWidth;
        int size = words.size();
        string new_word;
        // string str1 = "";
        // if (size == 1) 
        // {
        //     string zero((maxWidth-words[0].size()), ' ');
        //     str1 = words[0] + zero;
        //     return str1;
        // }
        // int remain_space = maxWidth;

        while(ind < size)
        {
            new_word = words[i];
            int s_size = new_word.size();
            if (remain_space >= s_size + 1)
                add_new_size(new_word);
            else{
                revolve_string(false);       
                add_new_size(new_word);
            }
            ind++;
        }
        revolve_string(true);
        return res;
    }
    void add_new_size(string new_word)
    {
        poor.append(new_word);
        poor_str_num++;
        remain_space -= new_word.size() - 1;
    }

    vector<string> revolve_string(bool end)
    {
        string res{' ', maxWidth};
        int size = poor.size();
        if(str_num == 1)
        {   
            ss_size = poor[0].size();
            res.replace(0, ss_size, poor[0]);
        }
        if (end)
        {
            for(int i )
        }
        for (int i = 0;i<size; i++)
        {
            space = remain_space/str_num;
            y_space = remain_space % str_num;
        }

        string black (' ', space);

        poor = "";
        poor_str_num = 0;
        remain_space = maxWidth;

    }

};


#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
    std::vector<std::string> result;
    int idx = 0; // 当前行的第一个单词的索引
    while (idx < words.size()) {
        int totalChars = words[idx].size(); // 当前行已有的字符数（包括当前单词）
        int last = idx + 1; // 当前行的最后一个单词的索引+1
        // 找到可以放入当前行的最后一个单词
        while (last < words.size() && totalChars + 1 + words[last - 1].size() <= maxWidth) {
            totalChars += 1 + words[last - 1].size();
            ++last;
        }
        
        // 处理最后一行或只有一词的行左对齐
        if (last == words.size() || last - idx == 1) {
            std::ostringstream oss;
            for (int i = idx; i < last; ++i) {
                oss << words[i];
                if (i < last - 1) oss << ' ';
            }
            oss << std::string(maxWidth - oss.str().size(), ' ');
            result.push_back(oss.str());
        } else { // 其他行，尽可能均匀分配空格
            std::ostringstream oss;
            int gaps = last - idx - 1; // 词之间的空格数
            int spaces = (maxWidth - totalChars) / gaps; // 每个间隙平均空格数
            int extraSpaces = (maxWidth - totalChars) % gaps; // 额外的空格
            
            for (int i = idx; i < last; ++i) {
                oss << words[i];
                if (i < last - 1) {
                    oss << std::string(spaces + (i - idx < extraSpaces ? 1 : 0), ' ');
                }
            }
            result.push_back(oss.str());
        }
        idx = last; // 更新下一行的第一个单词的索引
    }
    return result;
}
