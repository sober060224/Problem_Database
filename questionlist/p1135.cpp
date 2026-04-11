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

// 每个点都有两种可能
// 不满足要求就return，当前值太大了可以剪枝，一直将所有情况遍历完？
// 是不是第一次访问到就是最快的情况？并不是。
// 甚至每个点一开始访问到的情况都可能不是最优情况，最短路
void solve(vector<int> &k, int index, int &b, vector<bool> &visited, int &ans, int total)
{
    int n = k.size() - 1;
    if (index < 1 || index > n || visited[index] || total >= ans)
        return;
    if (index == b)
    {
        ans = min(ans, total);
        return;
    }

    visited[index] = true;
    solve(k, index + k[index], b, visited, ans, total + 1);
    solve(k, index - k[index], b, visited, ans, total + 1);
}
void test01()
{
    int n, a, b, ans = INT_MAX;
    cin >> n >> a >> b;
    vector<int> k(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    vector<bool> visited(n + 1, false);
    solve(k, a, b, visited, ans, 0);
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}

int solve2(vector<int> &k, int a, int b)
{
    int n = k.size() - 1;
    queue<int> q;
    vector<int> dis(n + 1, INT_MAX);
    q.push(a);
    dis[a] = 0;
    vector<int> pre = {1, -1};

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 2; i++)
        {
            int v = u + pre[i] * k[u];
            if (v < 1 || v > n || dis[v] != INT_MAX)
                continue;
            dis[v] = dis[u] + 1;
            if (v == b)
                return dis[v];
            q.push(v);
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 一层层遍历相邻状态，第一次访问到就是最优情况
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> k(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    if (a == b)
    {
        cout << 0;
        return 0;
    }
    cout << solve2(k, a, b);

    return 0;
}