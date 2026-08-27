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
    int numSquares(int n)
    {
        // 并不行，不能直接减最大的，这样并不是最优解
        // int cnt = 0;
        // while (n)
        // {
        //     int num = sqrt(n);
        //     n -= num * num;
        //     cnt++;
        // }
        // return cnt;

        // 难道是动态规划？每个数的最少数量最优解来自于每个更小值最优解的更新值
        // 两层循环吧，一层循环最大值就是这个值的根号值
        // 二层循环就是怎么减到0
        
        // 完全背包，有的价值就是有的钱，当前值的根号就是能选的最大值，每个数都可以重复选
        int m = sqrt(n);
        // 一维是能选的所有可能， 就算没有这个可能也要遍历上，后面会用到
        // 二维是拥有的所有钱
        vector<vector<int>> d(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            d[i][0] = 0;
        for (int i = 1; i <= n; i++)
            d[0][i] = INT_MAX / 2;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // 要选的值太大，只能不选这个值
                if (i * i > j)
                    d[i][j] = d[i - 1][j];
                else
                    d[i][j] = min(d[i][j - i * i] + 1, d[i - 1][j]);
            }
        }

        return d[m][n];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    Solution s;
    cout << s.numSquares(13);

    return 0;
}