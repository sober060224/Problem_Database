#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <class T>
void showve(vector<T> &a)
{
    for (ll i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void solve01(vector<pair<ll, ll>> &a, ll index, ll s, ll b, ll &ans, ll be)
{
    ll n = a.size() - 1;
    if (index > n)
    {
        ans = min(ans, abs(s - b));
        return;
    }

    // 一定要加return，不然是在index==be的时候分了三种情况进行递归
    // 而不是只分一种情况
    if (index == be)
    {
        solve01(a, index + 1, s, b, ans, be);
        return;
    }
    solve01(a, index + 1, s * a[index].first, b + a[index].second, ans, be);
    solve01(a, index + 1, s, b, ans, be);
}
void case01(vector<pair<ll, ll>> &a, ll &ans)
{
    int n = a.size() - 1;
    for (ll i = 1; i <= n; i++)
        solve01(a, 1, a[i].first, a[i].second, ans, i);
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // x *= si, y += bi, |x - y|最小，最少一种配料
    // 用个前缀和，前缀乘？也没规定要区间啊，n<=10直接dfs暴力？
    // 就是看选不选当前这个元素，动态规划？好像不太行，s和b不一定会选不是迭代过去的
    // dp[i] = min(dp[i - 1], abs(s * a[index].first - (b + a[index].second)));

    ll n;
    cin >> n;
    vector<pair<ll, ll>> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    ll ans = INT_MAX;

    // vector<ll> dp(n + 1, ll_MAX);
    // dp[1] = abs(a[1].first - a[1].second);
    // for (ll i = 2; i <= n; i++)
    //     dp[i] = min(dp[i - 1], abs(s * a[i].first - (b + a[i].second)));

    return 0;
}