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

    int t = 0;
    while (true)
    {
        cout << t++ << endl;
        system("data.exe > data.in");
        system("my.exe < data.in > my.out");
        system("std.exe < data.in > std.out");
        if (system("fc my.out std.out > diff.log"))
        {
            cout << "WA" << endl;
            break;
        }
    }

    return 0;
}