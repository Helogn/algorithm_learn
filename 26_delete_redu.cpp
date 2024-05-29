#include<vector>
#include<iostream>


using namespace std;
class Solution {
public:
/*
这个问题可以通过双指针技术来解决。我们用一个慢指针（记为slow）来记录新数组的当前位置，用一个快指针（记为fast）来遍历原数组。当快指针遇到与慢指针指向的元素不同的新元素时，就将其移到慢指针的下一个位置，并且慢指针向前移动一位。这样，慢指针之前的元素都是唯一的，并且保持了原有的顺序。最后，慢指针的位置就是新数组的长度，也即唯一元素的个数。
下面是这个问题的C++代码实现：
*/
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        auto size = nums.size();
        if (size == 1) return 1;
        int slow = 0;
        for (int high = slow + 1; high < size; high++)
        {
            if (nums[high] != nums[slow])
            {
                slow++;
                nums[slow] = nums[high];
            }
        }

        return slow + 1;
    }

};

void printvec(vector<int> vec)
{
    for(const auto& element : vec) {
        std::cout << element << " ";
    }

    // 如果你想在所有元素之后换行，可以这样做
    std::cout << std::endl;
}

int main()
{
    vector<int> vec = {1,2,3,3,4,5,6,7,7,7,8,9};

    Solution res = Solution();
    printvec(vec);
    int resnum = res.removeDuplicates(vec);
    // 遍历并打印vector中的每个元素
    printvec(vec);
    cout<<resnum<<endl;

    return 0;
}