/*
排序算法练习
*/

#include<iostream>
#include<vector>
using namespace std;
vector<int> quickSort(vector<int> vec, int mid_index = 0)
{
    size_t size = vec.size();
    cout<<"size of vector is "<<size<<endl;
    if (size <= 1) return vec;

    int mid_value = vec[mid_index];
    int head_ind = mid_index + 1;
    int end_ind = size - 1;
    bool right = true;
    /*
    循环条件错误：
    你的循环条件(head_ind == mid_index) && (end_ind == mid_index)在一开始就是错误的
    因为这会导致循环永远不会执行，
    因为head_ind和end_ind初始时就已经等于mid_index。
    正确的循环应该持续到head_ind和end_ind相遇为止。
    while((head_ind == mid_index) && (end_ind == mid_index))
    */
    while(head_ind == end_ind)
    {
        if (right)
        {
            if(vec[end_ind] < mid_value)
            {
                vec[mid_index] = vec[end_ind];
                right = false;
            }
            else
            {
                end_ind--;
            }
        }
        else
        {
            if(vec[head_ind] > mid_value)
            {
                vec[mid_index] = vec[head_ind];
                right = true;
            }
            else
            {
                head_ind++;
            }
        }
    }

    return vec;
    

}

int main()
{

    std::vector<int> vec1 = {1,7,2,8,3,7,11,2,90,12,14,15};
    quickSort(vec1);
    return 0;
}


