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

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false); // 主对角线: row + col
        vector<bool> diag2(2 * n - 1, false); // 副对角线: col - row + n - 1
        backtrack(0, n, board, col, diag1, diag2, ans);
        return ans;
    }

    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < n; ++c) {
            int d1 = row + c;
            int d2 = c - row + n - 1;
            if (col[c] || diag1[d1] || diag2[d2]) continue;
            board[row][c] = 'Q';
            col[c] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, board, col, diag1, diag2, ans);
            board[row][c] = '.';
            col[c] = diag1[d1] = diag2[d2] = false;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    Solution s;
    s.solveNQueens(4);

    return 0;
}