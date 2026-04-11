#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll matrixToll(vector<vector<ll>> &matrix)
{
    ll t = 0;
    for (auto &i : matrix)
        for (auto &j : i)
            t = t * 10 + j;
    return t;
}

void solve(vector<vector<ll>> &matrix)
{
    vector<vector<ll>> end = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    ll startll = matrixToll(matrix), endll = matrixToll(end);
    if (startll == endll)
    {
        cout << 0;
        return;
    }

    queue<vector<vector<ll>>> q;
    unordered_set<ll> us;
    q.push(matrix);
    us.insert(startll);

    vector<ll> dx = {0, -1, 1, 0, 0}, dy = {0, 0, 0, -1, 1};
    ll step = 0;

    while (!q.empty())
    {
        int sz = q.size(); // 当前层状态数
        for (int i = 0; i < sz; ++i)
        {
            vector<vector<ll>> u = q.front();
            q.pop();

            // 尝试点击每个格子
            for (ll x = 0; x < 3; ++x)
            {
                for (ll y = 0; y < 3; ++y)
                {
                    vector<vector<ll>> v = u;
                    // 翻转 (x,y) 及其上下左右
                    for (ll k = 0; k < 5; ++k)
                    {
                        ll nx = x + dx[k], ny = y + dy[k];
                        if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
                            v[nx][ny] ^= 1;
                    }
                    ll t = matrixToll(v);
                    if (us.find(t) != us.end())
                        continue;
                    if (t == endll)
                    {
                        cout << step + 1;
                        return;
                    }
                    q.push(v);
                    us.insert(t);
                }
            }
        }
        step++; // 进入下一层
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<vector<ll>> matrix(3, vector<ll>(3));
    for (ll i = 0; i < 3; ++i)
        for (ll j = 0; j < 3; ++j)
            cin >> matrix[i][j];
    solve(matrix);
    return 0;
}