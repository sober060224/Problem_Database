#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void pre()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), prefix(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            ans = max(ans, prefix[j] - prefix[i]);
    cout << ans;
}

void dp()
{
    // 状态转移方程
    // dp[i] = max(dp[i - 1] + a[i], a[i]);从前向后遍历，主要是双指针
    // 从后往前遍历，思路是从前往后看当前下标的最大字段和能到哪里
    // 发现最大字段和的末尾下标一直到值为负才改变
    // dp[i] = max(dp[i + 1] + a[i], a[i]);
    int n;
    cin >> n;
    // 注意pre初始化，如果是INT_MIN在减去一个新值之后会爆范围
    int ans = INT_MIN, pre = INT_MIN / 2;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        pre = max(pre + t, t);
        ans = max(ans, pre);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    dp();

    return 0;
}