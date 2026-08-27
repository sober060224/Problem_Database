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

// abce
// sfes
// adee
class Solution
{
public:
    bool dfs(vector<vector<char>> &board, int x, int y, vector<vector<bool>> visited, string word, int index)
    {
        int n = board.size(), m = board[0].size(), num = word.size();
        if (index == num)
            return true;

        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= n || nx < 0 || ny >= m || ny < 0 || visited[nx][ny] || board[nx][ny] != word[index])
                continue;

            visited[nx][ny] = true;
            if (dfs(board, nx, ny, visited, word, index + 1))
                return true;
            visited[nx][ny] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0]) 
                {
                    visited[i][j] = true;
                    if (dfs(board, i, j, visited, word, 1))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCESEEEFS";
    Solution s;
    if (s.exist(board, word))
        cout << 123;

    return 0;
}