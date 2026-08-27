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

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny] || grid[nx][ny] == '0')
                continue;
            visited[nx][ny] = true;
            dfs(grid, visited, nx, ny);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == false)
                {
                    dfs(grid, visited, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}