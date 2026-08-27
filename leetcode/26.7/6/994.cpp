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
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = 0;
        bool ok = false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] > 0)
                {
                    ok = true;
                    if (grid[i][j] == 2)
                        q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int length = q.size();
            for (int a = 0; a < length; a++)
            {
                int x = q.front().first, y = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dir[i][0], ny = y + dir[i][1];
                    if (nx >= m || nx < 0 || ny >= n || ny < 0 || grid[nx][ny] == 0 || grid[nx][ny] == 2)
                        continue;

                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }

            ans++;
        }

        if (!ok)
            return 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    return -1;

        return ans - 1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int a = 100, b = 2;
    int c = a > b ? 2 : 3;
    cout << c << endl;
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution s;
    cout << s.orangesRotting(grid);

    return 0;
}