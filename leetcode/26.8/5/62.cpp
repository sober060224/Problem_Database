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

// i * (i + 1) * (i + 2) * (i + n - 1) / (1 * 2 * ... * n)
// 
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> d(m + 1, vector<int>(n + 1, 0));
        d[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = d[i - 1][j] + d[i][j - 1];

        return d[m][n];
    }

    // 组合数学
    // 相当于在m + n - 2个格子里面选m - 1个位置或者n - 1个位置
    // 答案就是算出的组合数
    int solve(int m, int n)
    {
        int low = m + n - 2, high = min(m - 1, n - 1), ans = 1;
        for (int i = 1; i <= high; i++)
            ans = ans * (low + 1 - i) / i;
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    Solution s;
    cout << s.solve(3, 7);

    return 0;
}