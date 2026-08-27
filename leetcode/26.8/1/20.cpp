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
    bool isValid(string s)
    {
        stack<int> st;
        for (char c : s)
        {
            switch (c)
            {
            case '(':
                st.push(c);
                break;
            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
                break;
            case '{':
                st.push(c);
                break;
            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop();
                break;
            case '[':
                st.push(c);
                break;
            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop();
                break;
            default:
                break;
            }
        }

        if (st.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}