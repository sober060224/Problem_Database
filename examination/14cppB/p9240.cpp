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

// 返回0,1吧，0就是要增大，1就是减小
bool solve(vector<pair<int, int>> &metal, int mid)
{
    int n = metal.size();
    for (int i = 0; i < n; i++)
    {
        if (metal[i].first / mid > metal[i].second)
            return 0;
        else if (metal[i].first / mid < metal[i].second)
            return 1;
    }
    return 0;
}

// 0减小，1增大
bool check(vector<pair<int, int>> &metal, int mid)
{
    int n = metal.size();
    for (int i = 0; i < n; i++)
    {
        if (metal[i].first / mid < metal[i].second)
            return 0;
        else if (metal[i].first / mid > metal[i].second)
            return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 转换率最小最大值？
    // 两个二分答案
    int n;
    cin >> n;
    vector<pair<int, int>> metal(n);
    for (int i = 0; i < n; i++)
        cin >> metal[i].first >> metal[i].second;
    // 最大是1e9，最小是1

    // 先找最大值吧，如果除了之后得到的值比较大说明v小了，增大
    // 得到的值比较小说明大了，变小

    // 一直找到最大可能值
    // 一直找到最小可能值呢
    // 应该是判断条件那里不同，最大值是>=都要增大吗，最小值是<=都要变小吧
    int l = 1, r = 1e9, ans;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (!check(metal, mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    cout << ans << ' ';

    l = 1, r = 1e9;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (!solve(metal, mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    cout << ans;

    return 0;
}