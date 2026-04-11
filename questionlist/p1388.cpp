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

// signs:0-indexed
void solve(vector<int> signs, int index, int k, int multi, int add, int &ans, vector<int> a)
{
    int n = signs.size() - 1;
    if (index >= n)
    {
        n++;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++)
            dp[i][i] = a[i];
        for (int l = 2; l <= n; l++)
        {
            for (int i = 1; i + l - 1 <= n; i++)
            {
                int j = i + l - 1;
                for (int k = 1; k < j; k++)
                {
                    if (signs[k - 1] == 1)
                        dp[i][j] = max(dp[i][j], dp[i][k] * dp[k + 1][j]);
                    else
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        ans = max(ans, dp[1][n]);

        return;
    }

    if (multi < k)
    {
        signs[index] = 1;
        solve(signs, index + 1, k, multi + 1, add, ans, a);
    }
    if (add < n - k)
    {
        signs[index] = 2;
        solve(signs, index + 1, k, multi, add + 1, ans, a);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // n <= 15，dfs可能可行
    // 不改变它们的相对位置，在中间加入 k 个乘号和 (n−k−1) 个加号
    // 括号随便加，使最终结果尽量大
    // 括号随便加是怎么搞？
    // 直接全部枚举，乘号和加法……括号……
    // 先整乘法和加法
    // 刚才那道题一样两个if，两个变量分乘号加号，不行
    // 应该在最后选完全部符号才开始判断括号吧，还是怎么处理括号
    // 枚举括号吗？又用一个dfs枚举括号？
    // 好像不用管括号，是不是只要把乘法放在最后面，加法放在最前面就行了
    // 要让最终结果尽量大，应该让乘法两边的数字尽量大，也要管括号，不是把乘法后面就是最大的
    // 2^2n超了，不能又枚举括号又枚举符号的，剪枝？
    // 枚举乘和加法，类似矩阵链乘法枚举括号
    int n, k, ans = INT_MIN;
    cin >> n >> k;
    vector<int> signs(n), a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    solve(signs, 0, k, 0, 0, ans, a);
    cout << ans;

    return 0;
}