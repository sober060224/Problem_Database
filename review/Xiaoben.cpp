#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        stack<char> st;
        for (char c : s)
        {
            if (!st.empty() && st.top() == c)
                st.pop();
            else
                st.push(c);
        }
        cout << st.size() / 2 << endl;
    }

    return 0;
}