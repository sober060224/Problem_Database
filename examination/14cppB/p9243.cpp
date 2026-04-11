// 原来对外圈进行洪水填充和在1位置dfs遍历判断到不到得了边界都可以判断环内外
#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <class T>
void showve(vector<T> &a)
{
    for (size_t i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

// 从每个1开始八个方向遍历，走到圈外就不是子岛屿
bool loop(vector<string> &bridge, int i, int j, vector<vector<bool>> &t)
{
    int m = bridge.size() - 1, n = bridge[1].size();
    // 上下左右，上左右，下左右
    vector<int> dx = {-1, 1, 0, 0, -1, -1, 1, 1}, dy = {0, 0, -1, 1, -1, 1, -1, 1};
    for (int x = 0; x < 8; x++)
    {
        int nx = i + dx[x], ny = j + dy[x];
        // 能到圈外就不是子岛屿
        if (nx < 1 || nx > m || ny < 0 || ny >= n)
            return true;
        if (t[nx][ny] || bridge[nx][ny] == '1')
            continue;
        t[nx][ny] = true;
        if (loop(bridge, nx, ny, t))
            return true;
    }
    return false;
}

// visited处理成环？0就是没访问过，1就是访问过，2就是在环内
// 如果是访问过或者在环内就跳过，不将环内和访问过分开来不行吗
// 好像不行嘞，我一开始都不知道哪个方向在不在环内
// 是不是看看之前那个方法？能到边界就是不在环内？马上返回并确定不在环内然后再四周找
// 根本不行吧感觉，好像又行，不在环内又碰不到1的话就肯定能到边界吧
// 能到边界就不会成环，但是好像判断不完全，之前都是对0进行洪水填充的
// 我去了怎么处理成环啊
void solve(vector<string> &bridge, int i, int j, vector<vector<bool>> &visited)
{
    int m = bridge.size() - 1, n = bridge[1].size();
    // 上下左右
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    for (int x = 0; x < 4; x++)
    {
        int nx = i + dx[x], ny = j + dy[x];
        if (nx < 1 || nx > m || ny < 0 || ny >= n || visited[nx][ny] || bridge[nx][ny] == '0')
            continue;
        visited[nx][ny] = true;
        solve(bridge, nx, ny, visited);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 怎么处理子岛屿啊，还他妈有环
    // 怎么判断有没有成环，好像是在外圈dfs一下就是判断环内环外了
    // 有没有嘞？图就是dfs一下就行，那这个岛屿嘞？选出k个不同的格子？
    // 哦就是最后又能到一开始的那个点就是成环了，成环了就将里面的所有都变成1吧
    // 怎么把环里面的visited都变成true？
    int T;
    cin >> T;

    while (T--)
    {
        int ans = 0;
        int m, n;
        cin >> m >> n;
        vector<string> bridge(m + 1);
        for (int i = 1; i <= m; i++)
            cin >> bridge[i];
        vector<vector<bool>> visited(m + 1, vector<bool>(n, false));
        // 每个岛屿都分配一个特定的值，用来在判断子岛屿的时候不能走到其他岛屿上
        // 每次到一个岛屿就将岛屿所有位置都分配特定值，分配完之后
        // 在第一个到岛屿的地方四周遍历地方，不能走到别的岛屿上，但是还能走到边界就不是子岛屿
        // 遍历要从八个方向进行遍历，环内题目定义了严格封闭，有一点空位就不成环
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && bridge[i][j] == '1')
                {
                    vector<vector<bool>> t(m + 1, vector<bool>(n, false));
                    solve(bridge, i, j, visited);
                    if (loop(bridge, i, j, t))
                        ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}