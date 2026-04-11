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

void solve1()
{
    string a = "5 6 8 6 9 1 6 1 2 4 9 1 9 8 2 3 6 4 7 7 5 9 5 0 3 8 7 5 8 1 5 8 6 1 8 3 0 3 7 9 2 7 0 5 8 8 5 7 0 9 9 1 9 4 4 6 8 6 3 3 8 5 1 6 3 4 6 7 0 7 8 2 7 6 8 9 5 6 5 6 1 4 0 1 0 0 9 4 8 0 9 1 2 8 5 0 2 5 3 3";
    vector<int> d = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int cnt = 0;
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= d[i]; j++)
        {
            vector<int> date = {2, 0, 2, 3, i / 10, i % 10, j / 10, j % 10};
            int index = 0;
            for (int k = 0; k < a.size(); k += 2)
            {
                if (date[index] == a[k] - '0')
                    index++;
                if (index == 8)
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt;
}

void solve2()
{
    double n = 23333333;
    for (int i = 1; i <= n / 2; i++)
    {
        int j = n - i;
        double ans = - i / n * i * log2(i / n) - j / n * j * log2(j / n);
        if (abs(ans - 11625907.5798) < 0.001)
        {
            cout << i;
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // solve1();
    string a = "235", b = "11027421";
    // solve2();
    ans(a, b);

    return 0;
}