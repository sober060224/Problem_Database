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
        cin >> a[i];
    
    for (ll i = 0; i < k; i++)
    {
        ll index, value = INT_MAX;
        for (ll j = 1; j < a.size(); j++)
        {
            if (a[j] < value)
            {
                value = a[j];
                index = j;
            }
        }

        if (index > 1)
            a[index - 1] += a[index];
        if (index < a.size() - 1)
            a[index + 1] += a[index];
        a.erase(find(++a.begin(), a.end(), a[index]));
    }

    for (ll i = 1; i < a.size(); i++)
        cout << a[i] << ' ';

    return 0;
}