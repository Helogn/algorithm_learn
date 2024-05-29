/*
排序算法练习
*/

#include<iostream>
#include<vector>
using namespace std;


void quickSort(vector<int> &vec, int low , int high, int &ind)
{
    /*
    正确代码

    void quickSort(vector<int> &vec, int low, int high)
    {
        if (low >= high) return;

        int pivotIndex = partition(vec, low, high);
        quickSort(vec, low, pivotIndex - 1);
        quickSort(vec, pivotIndex + 1, high);
    }

    int partition(vector<int> &vec, int low, int high)
    {
        int pivot = vec[low];
        int left = low + 1;
        int right = high;

        while (true)
        {
            while (left <= right && vec[left] <= pivot) left++;
            while (right >= left && vec[right] > pivot) right--;

            if (right < left) break;
            else swap(vec[left], vec[right]);
        }

        swap(vec[low], vec[right]); // 将基准元素放到正确的位置
        return right;
    }

    */

    int left = low + 1;
    int right = high;
    // cout<<"ind: "<<ind++<<endl;
    // 每次选择列表的第一个字符
    if (left >= right) return;
    while(true)
    {
        while(left<=right && vec[left] <= vec[low]) left++;
        while(left<=right && vec[right] > vec[low]) right--;

        if (left > right) break;
        else swap(vec[left], vec[right]);

    }

    swap(vec[right], vec[low]);
    quickSort(vec, 0, right, ind);
    quickSort(vec, right + 1, high, ind);

    return;
}


void print_vector(vector<int> vec)
{
    for(int i = 0; i<vec.size(); i++)
    {
        cout << vec[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    std::vector<int> vec1 = {5,7,2,8,3,7,11,2,90,12,14,15};
    cout<<"start sorting, size: " <<vec1.size()<<endl;
    int ind = 0;
    quickSort(vec1, 0, vec1.size()-1, ind);
    print_vector(vec1);
    return 0;
}
