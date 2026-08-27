#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <class T>
void showve(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

// 3
// 0,0 0,2
// 0,1 1,2
// 0,2 2,2
// 1,0 0,1
// 1,1 1,1
// 1,2 2,1
// 2,0 0,0
// 
class Solution
{
public:
    // 数学观察规律
    // x = y, y = n - 1 - x
    // 原地修改数组等于一次转置一次翻转
    // 将两次循环改成一次循环也要观察规律，转置只需要遍历一半的数组就可以实现
    // 如果遍历整个数组来翻转，那合成一个循环里面就会出现已经处理好的位置被再次转置，出现错误位置
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    

    return 0;
}