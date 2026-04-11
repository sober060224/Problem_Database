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

// ans：1-indexed
void solve(int index, vector<char> ans, int pre, int total, int sign)
{
    int n = ans.size() - 1;
    if (index > n)
    {
        if (total + sign * pre == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << i << ans[i];
            }
            cout << n + 1 << endl;
        }
        return;
    }

    // +-空格
    vector<char> add = ans, sub = ans, space = ans;
    add[index] = '+';
    sub[index] = '-';
    space[index] = ' ';
    solve(index + 1, space, pre * 10 + index + 1, total, sign);
    solve(index + 1, add, index + 1, total + sign * pre, 1);
    solve(index + 1, sub, index + 1, total + sign * pre, -1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 数据范围较小，dfs可以，三路dfs
    // 每次都将上一次的选择记录下来，+-都是计算上一次的结果，空格也是计算上一次的结果
    // 枚举到了终点结果为零就加入答案
    int n;
    cin >> n;
    vector<char> ans(n);
    solve(1, ans, 1, 0, 1);

    return 0;
}