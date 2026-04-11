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

// chess:1-indexed，0：白，1：黑
void solve(vector<vector<int>> chess, int i, int j, int &ans)
{
    int n = 5;
    // 率先在横线、竖线或斜线上形成连续的五个同色棋子的一方获胜。
    if (i > n)
    {
        // 白要比黑刚好多下一个
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (chess[i][j] == 0)
                    x++;
                else
                    y++;
            }
        }
        if (x - y != 1)
            return;

        // win = true就说明有一方获胜，从横线上看
        // 从多个横线上看，有一个横线全相同就获胜
        bool win = true;
        for (int i = 1; i <= n; i++)
        {
            // ok = true就说明全都相同
            bool ok = true;
            for (int j = 2; j <= n; j++)
            {
                // 横看
                if (chess[i][j] != chess[i][j - 1])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return;
        }

        // 竖看
        // 有一个竖线上全相同就获胜
        for (int i = 1; i <= n; i++)
        {
            // ok = true就说明全都相同
            bool ok = true;
            for (int j = 2; j <= n; j++)
            {
                // 横看
                if (chess[j][i] != chess[j - 1][i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return;
        }

        // 有一个不同就不可能有胜负
        for (int i = 2; i <= n; i++)
        {
            if (chess[i][i] != chess[i - 1][i - 1])
            {
                win = false;
                break;
            }
        }
        if (win)
            return;
        win = true;
        for (int i = 2; i <= n; i++)
        {
            if (chess[i][6 - i] != chess[i - 1][6 - i + 1])
            {
                win = false;
                break;
            }
        }
        if (win)
            return;

        ans++;
        return;
    }

    for (int x = 0; x < 2; x++)
    {
        chess[i][j] = x;
        if (j < 5)
            solve(chess, i, j + 1, ans);
        else
            solve(chess, i + 1, 1, ans);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    /*
    5×5 的棋盘，黑白两色的棋子来决出胜负，和棋（平局） 作为彼此友谊的见证。
    共有 25 个格子供下棋使用。
    白棋（小蓝）具有先手优势
    交替在棋盘上放置各自的棋子，每次仅放置一枚。
    所有 25 个棋盘格都被下满棋子，而未决出胜负时，游戏以平局告终。
    终局不同看成不同情况，终局相同而落子顺序不同看成同一种情况
    有多少种不同的棋局情况，既确保棋盘下满又保证比赛结果为平局。
    */
    // 填空题，直接dfs暴搜
    // 递归横坐标，循环纵坐标，横坐标到了6才结束递归判断情况是否相符
    // 怎么选择？轮流下棋
    int ans = 0;
    vector<vector<int>> chess(6, vector<int>(6));
    // solve(chess, 1, 1, ans);
    cout << 3126376;

    return 0;
}