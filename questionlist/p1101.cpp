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

// 一次递归可能会找到多个单词，找到一个单词就要开始定方向
void solve(vector<vector<char>> &matrix, vector<pair<int, int>> path, vector<vector<bool>> &visited, int i, int j, int dir)
{
    int n = matrix[0].size() - 1, index = path.size();

    if (index == 7)
    {
        for (auto t : path)
            visited[t.first][t.second] = true;
        return;
    }

    // 上下左右，右左上左右下
    vector<int> dx = {-1, 1, 0, 0, -1, -1, 1, 1}, 
    dy = {0, 0, -1, 1, 1, -1, -1, 1};
    string s = "yizhong";
    int newx, newy;

    // 如果有方向了就不用循环了，直接对着方向递归
    if (dir == -1)
    {
        for (int x = 0; x < 8; x++)
        {
            newx = i + dx[x], newy = j + dy[x];
            if (newx < 1 || newx > n || newy < 1 || newy > n || matrix[newx][newy] != s[index])
                continue;
            path.push_back({newx, newy});
            // 没有添加回溯导致path长度比实际偏大，影响
            solve(matrix, path, visited, newx, newy, x);
            path.pop_back();
        }
    }
    else
    {
        newx = i + dx[dir], newy = j + dy[dir];
        if (newx < 1 || newx > n || newy < 1 || newy > n || matrix[newx][newy] != s[index])
            return;
        path.push_back({newx, newy});
        solve(matrix, path, visited, newx, newy, dir);
        path.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> matrix(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];

    // dfs深度找yizhong？
    // 两层循环遍历矩阵，找到y或者g才开始8个方向递归，只遍历没标记的位置
    // 标记单词呢？用*代替
    // 找单词就记录路径，找到单词后才将路径都标记？
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (matrix[i][j] == 'y')
            {
                vector<pair<int, int>> path;
                path.push_back({i, j});
                // visited[i][j] = true;
                solve(matrix, path, visited, i, j, -1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (visited[i][j] ? matrix[i][j] : '*');
        cout << endl;
    }

    return 0;
}