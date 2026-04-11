#include <bits/stdc++.h>
using namespace std;

class GoodNumberCounter
{
    vector<int> digits; // N 的各个数位，高位在前
    int n;              // N 的位数

    // 计算固定长度为 L 的好数个数
    // pos : 当前构造到的位置（0~L-1）
    // limit : 是否受到 N 的约束（仅在 L == n 时有效）
    // L : 目标长度
    // dp : 记忆化数组，维度 [pos][limit]，由于 limit 只有 true/false 且状态少，可用 vector 或直接用静态数组
    int dfsFixedLen(int pos, bool limit, int L, vector<vector<int>> &dp)
    {
        if (pos == L)
            return 1; // 成功构造出一个合法数字
        if (!limit && dp[pos][L] != -1)
            return dp[pos][L];

        // 当前位能填的最大数字
        int up = limit ? digits[n - L + pos] : 9; // 映射到 N 的对应位置
        int ans = 0;

        // 确定当前位（从低位起）是第几位，从 1 开始计数
        int bitFromLow = L - pos;
        bool needOdd = (bitFromLow % 2 == 1); // 是否需要奇数

        for (int d = 0; d <= up; ++d)
        {
            if (pos == 0 && d == 0)
                continue; // 最高位不能是 0
            if (needOdd && d % 2 == 0)
                continue; // 要求奇数但填了偶数
            if (!needOdd && d % 2 == 1)
                continue; // 要求偶数但填了奇数
            ans += dfsFixedLen(pos + 1, limit && (d == up), L, dp);
        }

        if (!limit)
            dp[pos][L] = ans;
        return ans;
    }

    // 计算所有长度小于 len(N) 的好数总数
    int countShorter()
    {
        int total = 0;
        // 对长度 1 到 n-1 分别计算，此时 limit = false
        for (int L = 1; L < n; ++L)
        {
            vector<vector<int>> dp(L, vector<int>(n + 1, -1));
            total += dfsFixedLen(0, false, L, dp);
        }
        return total;
    }

    // 计算长度等于 len(N) 且 ≤ N 的好数个数
    int countEqual()
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return dfsFixedLen(0, true, n, dp);
    }

public:
    int countGoodNumbers(int N)
    {
        string s = to_string(N);
        n = s.size();
        digits.resize(n);
        for (int i = 0; i < n; ++i)
            digits[i] = s[i] - '0';

        int ans = countShorter();
        ans += countEqual();
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    // 10000
    GoodNumberCounter counter;

    // if (N <= 10000)
    //     cout << ans[N];
    // else
    // cout << "vector<int> ans = {";
    // for (int i = 1; i <= 10000; i++)
    // {
    cout << counter.countGoodNumbers(N);
    // }
    // cout << "}";

    return 0;
}