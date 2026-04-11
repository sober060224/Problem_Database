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
    int k;
    string s;
    char c1, c2;
    int slength = rand() % 100 + 2;
    c1 = 'a' + rand() % 26, c2 = 'a' + rand() % 26;
    for (int i = 0; i < slength; i++)
    {
        int j = rand() % 2;
        if (j)
            s.push_back(c1);
        else
            s.push_back(c2);
    }
    k = rand() % slength;
    if (k == 0)
        k += 2;
    cout << k << endl;
    cout << s << ' ' << c1 << ' ' << c2;

    return 0;
}