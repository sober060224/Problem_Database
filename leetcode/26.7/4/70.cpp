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

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> d(n + 1);
        d[1] = 1;
        if (n >= 2)
            d[2] = 2;

        for (int i = 3; i <= n; i++)
            d[i] = d[i - 1] + d[i - 2];

        return d[n];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}