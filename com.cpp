#include<vector>
#include<iostream>
#include"com.h"
using namespace std;

void printvec(vector<int> vec)
{
    for(const auto& element : vec) {
        cout << element << " ";
    }

    // 如果你想在所有元素之后换行，可以这样做
    cout << endl;
}