#include <bits/stdc++.h>
using namespace std;
#define ll long long

void showmap(map<ll, ll, greater<ll>> &area)
{
    cout << "--------------------------------" << endl;
    for (pair<ll, ll> t : area)
        cout << t.first << ' ' << t.second << endl;
}

void showve(vector<ll> &a)
{
    for (ll i = 1; i < a.size(); i++)
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

    map<ll, ll, greater<ll>> area;
    ll n, m, k;
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        area[a] += b;
    }
    area[k] += 0;

    // 从天数最长的区域开始，不断降低天数最长的
    // 当前资源比要要耗费资源还少，当前资源和k一样就退出
    ll ans = -1;
    auto head = area.begin();
    while (m >= head->second && head->first > k)
    {
        // showmap(area);
        auto next = head;
        next++;
        ll cost = (head->first - next->first) * head->second;
        if (m > cost)
        {
            m -= cost;
            next->second += head->second;
            area.erase(head);
        }
        else
        {
            ans = head->first;
            while (m >= head->second)
            {
                m -= head->second;
                ans--;
                // showmap(area);
            }
            cout << ans;
            break;
        }
        head = area.begin();
        // showmap(area);
    }

    if (ans == -1)
        cout << head->first;

    return 0;
}

