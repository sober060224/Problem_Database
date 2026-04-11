#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define ll long long

class node
{
public:
    ll v, index, s;
    bool operator<(const node &other) const
    {
        if (v == other.v)
            return index > other.index;
        return v > other.v;
    }
    node() {}
    node(ll v, ll index, ll s) : v(v), index(index), s(s) {}
};

template <class T>
void showve(vector<T> &a)
{
    for (ll i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    cout << "---------------------------" << endl;
}

void showpq(priority_queue<node> pq)
{
    while (!pq.empty())
    {
        cout << pq.top().v << ' ' << pq.top().index << ' ' << pq.top().s << endl;
        pq.pop();
    }
    cout << "---------------------------" << endl;
}

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 用集合和数组分别存数列，集合还要将下标一起存下去，自定义排序规则
    // 下标越小的放在越前面
    // 每次操作都先在集合里面取第一个数，通过这个数找到下标前后的值
    // 更新集合和数组里面的值
    // 不太行啊，删除了之后剩下全部下标都会变的
    // 要快删快加快找？
    // 原本的序列要快删快加
    // 快找倒是容易吗？好像用一个集合可以吧，每次找到那个点的值然后再找相邻位置的值就行
    // 相邻位置的值二分找到然后更新就行
    // 集合好像不能更新，只能删加
    // 原本的序列用链表？链表不能快找嘞
    // 还是数组吧？还是不要原来的序列了？
    // 直接全用集合存起来，也存下标，删除之后下标都会变！！！
    // 那就也变下标？？？变值变下标？

    // 那就是有k次操作
    // 每次操作的时候找集合里面的第一个结构体
    // 记录这个结构体的下标和值
    // 判断这个下标是不是0，是不是最后一个值，用size那样的判断是不是最后一个值
    // 诶不对啊，他妈的这个更新值的后面的数全部的下标都要更新啊！！！这玩鸡毛

    // 用数组存原始序列
    // 用数组组双向链表，存的都是下标，可以随机访问相邻数组元素
    // 用小根堆存所有数据，记录状态，是不是最新状态
    // 用一个数组记录每个下标最新状态
    // 只更新最新状态数据
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> lst(n + 1);
    vector<ll> state(n + 1), a(n + 1);
    vector<bool> existed(n + 1, true);
    priority_queue<node> pq;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        pq.push(node(a[i], i, 0));
        lst[i].second = i + 1, lst[i].first = i - 1;
    }
    auto start = high_resolution_clock::now();
    lst[1].first = -1, lst[n].second = -1;

    // 只需要将新状态放进去，不一定要更新数据
    for (ll i = 0; i < k; i++)
    {
        while (!pq.empty() && state[pq.top().index] != pq.top().s)
            pq.pop();
        auto t = pq.top();
        pq.pop();
        ll index = t.index, value = t.v, left = lst[index].first, right = lst[index].second;
        existed[index] = false;

        if (left != -1)
        {
            lst[left].second = right;
            a[left] += value;
            state[left]++;
            // 加入状态不能是当前状态+1，而是那个数字的状态+1
            pq.push(node(a[left], left, state[left]));
        }
        if (right != -1)
        {
            lst[right].first = left;
            a[right] += value;
            state[right]++;
            pq.push(node(a[right], right, state[right]));
        }
    }

    for (ll i = 1; i <= n; i++)
        if (existed[i])
            cout << a[i] << ' ';
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << endl << duration.count();

    return 0;
}