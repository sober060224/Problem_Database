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

void solve()
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    srand((unsigned int)time(nullptr));
    int n, k;
    n = rand() % 10000 + 2, k = rand() % n;
    if (k < 1)
        k++;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = rand() % 100;
    cout << n << ' ' << k << endl;
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';

    return 0;
}