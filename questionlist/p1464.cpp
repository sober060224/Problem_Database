#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll cnt = 0;
vector<vector<vector<ll>>> memo(25, vector<vector<ll>>(25, vector<ll>(25)));

template <class T>
void showve(vector<T> &a)
{
    for (ll i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

ll solve(ll a, ll b, ll c)
{
    // abc太大会超界，先对abc进行处理再记忆化
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return solve(20, 20, 20);

    if (memo[a][b][c] != 0)
        return memo[a][b][c];
    
    if (a < b && b < c)
        return memo[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
    else
        return memo[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    while (1)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << endl;
    }

    return 0;
}