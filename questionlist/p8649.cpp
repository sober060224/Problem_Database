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

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        ll t;
        cin >> t;
        a[i] = a[i - 1] + t;
    }
    // showve(a);
    // a[j] % k == a[i - 1] % k
    for (ll i = 1; i <= n; i++)
        a[i] %= k;
    // showve(a);

    // ll ans = 0;
    // for (ll i = 1; i <= n; i++)
    //     for (ll j = i; j <= n; j++)
    //         if ((a[j] - a[i - 1]) % k == 0)
    //             ans++;
    // cout << ans;

    vector<ll> cnt(k);
    for (ll i = 0; i <= n; i++)
        cnt[a[i]]++;
    // showve(cnt);
    ll ans = 0;
    for (ll i = 0; i < k; i++)
        ans = (cnt[i] * (cnt[i] - 1)) / 2 + ans;
    cout << ans;

    return 0;
}