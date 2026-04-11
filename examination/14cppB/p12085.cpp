#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;

const int N = 500005;
int n, k;
ll a[N];
bool flag[N]; // 标记是否被删除
set<pair<ll, int>>::iterator pos[N];

// 双向链表，用于快速找到相邻的未删除元素
struct List
{
    int l, r;
} lst[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        lst[i].l = i - 1;
        lst[i].r = i + 1;
    }
    auto start = high_resolution_clock::now();
    lst[1].l = lst[n].r = -1; // 边界处理

    // set 存储 (value, id)，默认按 value 升序，value 相同按 id 升序（符合题意）
    set<pair<ll, int>> s;
    // 记录每个 id 在 set 中的迭代器，用于 O(1) 删除旧值

    for (int i = 1; i <= n; ++i)
    {
        auto it = s.insert({a[i], i}).first;
        pos[i] = it;
    }

    for (int step = 1; step <= k; ++step)
    {
        // 取最小值节点（set 自动排序，begin() 即是最小且最靠前的）
        auto it = s.begin();
        ll val = it->first;
        int id = it->second;

        s.erase(it);     // 从 set 中删除
        flag[id] = true; // 标记已删除

        int left = lst[id].l;
        int right = lst[id].r;

        // 处理左邻居
        if (left != -1)
        {
            s.erase(pos[left]); // 删除旧值
            a[left] += val;     // 更新值
            auto new_it = s.insert({a[left], left}).first;
            pos[left] = new_it;  // 更新迭代器
            lst[left].r = right; // 链表跳过 id
        }

        // 处理右邻居
        if (right != -1)
        {
            s.erase(pos[right]); // 删除旧值
            a[right] += val;     // 更新值
            auto new_it = s.insert({a[right], right}).first;
            pos[right] = new_it; // 更新迭代器
            lst[right].l = left; // 链表跳过 id
        }
    }

    // 输出未被删除的元素
    for (int i = 1; i <= n; ++i)
        if (!flag[i])
            cout << a[i] << ' ';
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cerr << endl
         << duration.count();
         
    return 0;
}