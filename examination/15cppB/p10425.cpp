#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showve(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    string d;
    cin >> n >> d;
    reverse(d.begin(), d.end());
    // 将字符串改成整数数组
    vector<int> a;
    // 小数点前一个数下标
    int idx;

    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] != '.')
            a.push_back(d[i] - '0');
        else
            idx = i - 1;
    }

    // 每位乘2
    for (int i = 0; i < n; i++)
    {
        int length = a.size();
        for (int j = 0; j < length; j++)
            a[j] *= 2;
        for (int j = 0; j < length - 1; j++)
        {
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
        }
        if (a[length - 1] >= 10)
        {
            a.push_back(a[length - 1] / 10);
            a[length - 1] %= 10;
        }
    }

    // 四舍五入
    if (a[idx] >= 5)
    {
        a[idx + 1]++;
        int length = a.size();
        for (int j = idx + 1; j < length - 1; j++)
        {
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
        }
        if (a[length - 1] >= 10)
        {
            a.push_back(a[length - 1] / 10);
            a[length - 1] %= 10;
        }
    }

    // 输出答案
    for (int i = a.size() - 1; i > idx; i--)
        cout << a[i];

    return 0;
}