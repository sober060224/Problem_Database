#include <bits/stdc++.h>
using namespace std;
#define ll long long

void ans(string a, string b)
{
    string ans [] = {
        a, // 双引号中替换为 A 题的答案
        b, // 双引号中替换为 B 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
}

template <class T>
void showve(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void solveB()
{
    // 2022年，只要存在任意连续三位数就是顺子日期
    // 计数一共有多少个
    vector<int> d = {0, 31, 28, 31, 30, 31,
         30, 31, 31, 30, 31, 
         30, 31};
    int cnt = 0;
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= d[i]; j++)
        {
            vector<int> date = {2, 0, 2, 2, i / 10, i % 10, j / 10, j % 10};
            int t = 0;
            bool ok = false;
            // 出现了连续三位数就计数日期
            // 从2开始的每个数开始看三个数
            for (int m = 3; m < date.size(); m++)
            {
                for (int n = m + 1; n < date.size(); n++)
                {
                    if (date[n] == date[n - 1] + 1)
                    {
                        t++;
                    }
                    else
                        break;
                    if (t == 3)
                    {
                        cnt++;
                        ok = true;
                        break;
                    }
                }
                if (ok)
                    break;
            }
        }
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // A循环
    string a = "1478";
    // B暴力枚举
    // solveB();
    string b = "14";
    ans(a, b);

    return 0;
}