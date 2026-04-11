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

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 每次都看前一个数的最后一个数和当前数的第一个数
    // 如果不相同就去掉，感觉可以每个数都用个循环找到这个数的最后一个数
    // 每次都用循环也才最多5次操作
    // 开始就是第一个数的最后一个数
    // 要最少的删除个数
    // 最少从中删除多少个数，可以使剩下的序列是接龙序列？
    // 求最长接龙序列，最后用n减去得到最少删除多个数
    int n;
    cin >> n;
    string a;
    vector<int> dp(10);
    int num = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        int l = a.size() - 1;
        dp[a[l] - '0'] = max(dp[a[l] - '0'], dp[a[0] - '0'] + 1);
        num = max(num, dp[a[l] - '0']);
    }
    cout << n - num;

    return 0;
}