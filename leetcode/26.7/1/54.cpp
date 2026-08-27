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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size(), dir = 0;
        vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0}, ans;
        // 用bfs队列遍历？遍历图一样，定一个方向
        // 碰到了边界或者访问过的东西就换方向，然后一直访问一直放到数组内
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
        q.push({0, 0});
        ans.push_back(matrix[0][0]);

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            int x = front.first, y = front.second;
            visited[x][y] = true;

            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx >= n || ny >= m || ny < 0 || visited[nx][ny])
            {
                dir++;
                dir %= 4;
                nx = x + dx[dir], ny = y + dy[dir];
                if (nx >= n || ny >= m || ny < 0 || visited[nx][ny])
                    break;
            }

            q.push({nx, ny});
            ans.push_back(matrix[nx][ny]);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<vector<int>> matrix = {{1}};
    Solution s;
    vector<int> t = s.spiralOrder(matrix);
    showve(t);

    return 0;
}