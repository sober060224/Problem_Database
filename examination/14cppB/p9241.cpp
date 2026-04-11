#include <bits/stdc++.h>
using namespace std;
#define ll long long

class plane
{
public:
    int t, d, l;
    plane() {}
    plane(int t, int d, int l) : t(t), d(d), l(l) {}
};

template <class T>
void showve(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

// dfs暴力枚举所有情况2^n*n*T也才102400
// 随便放飞机，先将所有情况枚举出来？
// 怎么枚举？
// 一开始就从下标1开始，如果枚举到第n个数就退出，输出YES并返回到调用处
// 每次选择都从n个选吧，选过不能再选，看看合理性再选择，所有情况都考虑过了还不合理就会自己回去
// 返回true就输出NO
bool solve(vector<plane> &planes, int index, vector<bool> &visited, int start)
{
    int n = planes.size() - 1;
    if (index > n)
    {
        cout << "YES" << endl;
        return false;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] || planes[i].d + planes[i].t < start)
            continue;
        visited[i] = true;
        // 最早可以在ti开始降落
        if (!solve(planes, index + 1, visited, max(planes[i].t, start) + planes[i].l))
            return false;
        visited[i] = false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<plane> planes(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> planes[i].t >> planes[i].d >> planes[i].l;
        // sort(++planes.begin(), planes.end(), [](plane &a, plane &b)
        //      {
        //     if (a.t + a.d == b.t + b.d)
        //         return a.l < b.l;
        //     return a.t + a.d < b.t + b.d; });
        // // 贪心思路
        // // 每个起点一开始是ti，结束时间是ti+di，新起点是ti+li?
        // // 先将结尾最早的、最紧迫的先算了，然后更新起点
        // // 下一个新起点是哪里？新起点：刚更新的新起点+li
        // // 找下一个起点比起点更晚的区间，再更新起点
        // // 找不到下一个起点就输出NO
        // // 所有遍历完标志没变就输出YES
        // // 先将降落过程最少的先算了?不行啊
        // // 先将开始时间最少的先算了?好像也不行
        // vector<bool> visited(n + 1, false);
        // visited[1] = true;
        // int start = planes[1].t + planes[1].l;
        // bool ok;
        // for (int i = 2; i <= n; i++)
        // {
        //     // 在起点更晚的区间里面找一个最晚起点比上区间结束点更晚的，同时让新起点尽可能早
        //     ok = false;
        //     int j;
        //     for (j = 1; j <= n; j++)
        //     {
        //         if (!visited[j] && planes[j].t + planes[j].d >= start)
        //         {
        //             ok = true;
        //             break;
        //         }
        //     }
        //     if (!ok)
        //         break;
        //     else
        //     {
        //         start = max(planes[j].t, start) + planes[j].l;
        //         visited[j] = true;
        //     }
        // }
        // if (!ok)
        //     cout << "NO" << endl;
        // else
        //     cout << "YES" << endl;
        vector<bool> visited(n + 1, false);
        if (solve(planes, 1, visited, 0))
            cout << "NO" << endl;
    }

    return 0;
}