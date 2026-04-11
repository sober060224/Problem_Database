// 似乎是2^2500运算量
// #include <bits/stdc++.h>
// #include "p3392.h"
// using namespace std;
// #define ll long long
// void showve(vector<char> &a)
// {
//     for (int i = 1; i < a.size(); i++)
//         cout << a[i] << ' ';
//     cout << endl;
// }
// void solve(vector<vector<char>> &matrix, int x, int y, string des, int &total, int &best)
// {
//     int N = matrix.size() - 1, M = matrix[0].size() - 1;
//     // 从最上方若干行（至少一行）的格子全部是白色的；
//     // 接下来若干行（至少一行）的格子全部是蓝色的；
//     // 剩下的行（至少一行）全部是红色的；
//     if (x == N + 1)
//         return subSolve(matrix, des, total, best);
//     for (int i = 0; i < des.size(); i++)
//     {
//         // showMatrix(matrix);
//         if (matrix[x][y] == des[i])
//             continue;
//         matrix[x][y] = des[i];
//         if (y % M == 0)
//             solve(matrix, x + 1, 1, des, ++total, best);
//         else
//             solve(matrix, x, y + 1, des, ++total, best);
//     }
// }
// void subSolve(std::vector<std::vector<char>> &matrix, std::string &des, int &total, int &best)
// {
//     showMatrix(matrix);
//     int N = matrix.size() - 1, M = matrix[0].size() - 1;
//     // w = false第一行不全都是白色
//     bool w = true;
//     for (int i = 1; i <= M; i++)
//     {
//         if (matrix[1][i] != des[0])
//         {
//             w = false;
//             break;
//         }
//     }
//     if (!w)
//         return;
//     // 找蓝色行的行位置
//     // row = N接下来没有若干行都是蓝色，或者最后一行才全是蓝色，不可行
//     int row = 1;
//     for (; row <= N; row++)
//         if (matrix[row][1] == des[1])
//             break;
//     if (row == N)
//         return;
//     // b = false不是接下来若干行全都蓝色
//     bool b = true;
//     for (int i = 1; i <= M; i++)
//     {
//         if (matrix[row][i] != des[1])
//         {
//             b = false;
//             break;
//         }
//     }
//     if (!b)
//         return;
//     // 找红色行
//     bool r = false;
//     for (; row <= N; row++)
//     {
//         if (matrix[row][1] == des[2])
//         {
//             r = true;
//             break;
//         }
//     }
//     if (!r)
//         return;
//     // 剩下行是不是都是红色
//     for (; row <= N; row++)
//     {
//         for (int i = 1; i <= M; i++)
//         {
//             if (matrix[row][i] != des[2])
//             {
//                 r = false;
//                 break;
//             }
//         }
//     }
//     if (!r)
//         return;
//     if (total < best)
//         best = total;
//     return;
// }
// void showMatrix(std::vector<std::vector<char>> &matrix)
// {
//     for (vector<char> v : matrix)
//         showve(v);
// }
// void testsubSolve()
// {
//     vector<vector<char>> matrix = {{'0', 'a', 'a', 'a', 'a','a'},{'a','W','W','W','W','W',},{'a','B', 'B', 'B', 'B', 'B',},
//                                 {'a','R','R','R','R','R',},{'a','R','R','R','R','R',}};
//     string des = "WBR";
//     int total = 1, best = 100;
//     subSolve(matrix, des, total, best);
//     cout << total << ' ' << best;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     // testsubSolve();
//     int N, M;
//     cin >> N >> M;
//     vector<vector<char>> matrix(N + 1, vector<char>(M + 1));
//     for (int i = 1; i <= N; i++)
//         for (int j = 1; j <= M; j++)
//             cin >> matrix[i][j];
//     int total = 0, best = INT_MAX;
//     string des = "WBR";
//     solve(matrix, 1, 1, des, total, best);
//     cout << best << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
   for (int i = 1; i < a.size(); i++)
       cout << a[i] << ' ';
   cout << endl;
}

int solve(string s, char c)
{
    int t = 0;
    for (char ch : s)
        if (ch != c)
            t++;
    return t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;
    vector<string> matrix(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> matrix[i];

    /*
    从最上方若干行（至少一行）的格子全部是白色的；
    接下来若干行（至少一行）的格子全部是蓝色的；
    剩下的行（至少一行）全部是红色的；
    */
    vector<int> w(N + 1), b(N + 1), r(N + 1);
    for (int i = 1; i <= N; i++)
    {
        w[i] = w[i - 1] + solve(matrix[i], 'W');
        b[i] = b[i - 1] + solve(matrix[i], 'B');
        r[i] = r[i - 1] + solve(matrix[i], 'R');
    }
    int ans = INT_MAX;
    for (int i = 1; i < N; i++)
        for (int j = i + 1; j < N; j++)
            ans = min(ans, w[i] + b[j] - b[i] + r[N] - r[j]);

    cout << ans << endl;

    return 0;
}