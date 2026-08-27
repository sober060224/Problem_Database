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

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // 感觉动态规划试试？
        // 最后一个金额可能会从两个地方来，前一个位置不选最后一个金额，前前面一个位置选这个金额
        // 别的地方的金额都可能到前和前前面位置上，因为多选一个位置的金额获得的总金额并不会减少
        int n = nums.size();
        vector<int> d(n + 1);
        d[1] = nums[0];

        for (int i = 1; i < n; i++)
            d[i + 1] = max(d[i], d[i - 1] + nums[i]);

        return d[n];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);



    return 0;
}