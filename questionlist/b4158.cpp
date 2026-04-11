#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(int t)
{
    for (int i = 2; i <= sqrt(t); i++)
        if (t % i == 0)
            return false;
    return true;
}
void test01()
{
    int t;
    cin >> t;
    if (isPrime(t))
        cout << "ok";
    else
        cout << "no";
}

template <class T>
void showve(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

bool solve(string t, int index, int total)
{
    int n = t.size();
    if (index >= n)
    {
        if (isPrime(total))
        {
            cout << total << endl;
            return false;
        }
        return true;
    }
    // 每次循环都将数值*10更新，递归到末尾就判断质数
    // 是质数就直接输出并返回false到调用处，否则返回true到调用处输出-1
    for (; index < n; index++)
    {
        if (t[index] == '*')
            break;
        total = total * 10 + (t[index] - '0');
    }
    if (index < n)
    {
        for (int i = 0; index < n && i <= 9; i++)
            if (!solve(t, index + 1, total * 10 + i))
                return false;
    }
    else
    {
        if (!solve(t, index, total))
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // test01();

    // 数据量较小，dfs
    // 用string存每个数据，从头开始递归找到*才递归下一个
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (solve(s, 0, 0))
            cout << -1 << endl;
    }

    return 0;
}