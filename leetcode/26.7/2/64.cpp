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

class Node
{
public:
    int x, y, w;
    Node(int x, int y, int w) : x(x), y(y), w(w) {}
    bool operator<(const Node &other) const
    {
        return w > other.w;
    }
};

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        priority_queue<Node> pq;
        pq.push(Node(0, 0, grid[0][0]));
        vector<vector<int>> dis(m + 1, vector<int>(n + 1, INT_MAX)), dir = {{1, 0}, {0, 1}};
        dis[0][0] = grid[0][0];

        while (!pq.empty())
        {
            auto t = pq.top();
            pq.pop();
            int x = t.x, y = t.y, w = t.w;
            if (dis[x][y] != t.w)
                continue;
            if (x == m - 1 && y == n - 1)
                return w;

            for (int i = 0; i < 2; i++)
            {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx >= m || ny >= n)
                    continue;
                int nw = grid[nx][ny];
                    
                if (dis[nx][ny] > dis[x][y] + nw)
                {
                    pq.push(Node(nx, ny, dis[x][y] + nw));
                    dis[nx][ny] = dis[x][y] + nw;
                }
            }
        }

        return 0;
    }

    int solve2(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> d(m + 1, vector<int>(n + 1, INT_MAX));
        d[0][1] = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                d[i + 1][j + 1] = min(d[i][j + 1], d[i + 1][j]) + grid[i][j];
        return d[m][n];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    Solution s;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << s.minPathSum(grid);

    return 0;
}