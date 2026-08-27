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
    void dfs(int index, string s, vector<string> &ans, int m)
    {
        int n = s.size() / 2;
        if (index >= 2 * n)
        {
            stack<char> st;
            for (int i = 0; i < s.size(); i++)
            {
                switch (s[i])
                {
                case '(':
                    st.push(s[i]);
                    break;
                case ')':
                    if (st.empty() || st.top() != '(')
                        return;
                    st.pop();
                    break;
                default:
                    break;
                }
            }
            ans.push_back(s);

            return;
        }

        if (m < n)
        {
            s[index] = '(';
            dfs(index + 1, s, ans, m + 1);
        }
        s[index] = ')';
        dfs(index + 1, s, ans, m);
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s(2 * n, ' ');
        dfs(0, s, ans, 0);
        return ans;
    }

    // 枚举括号数量，左括号必须先放，每次放括号必须保证右括号比左括号更少
    void solve2_(int left, int right, vector<string> &ans, string s)
    {
        int n = s.size();
        if (left + right >= n)
        {
            ans.push_back(s);
            return;
        }

        if (left < n / 2)
        {
            s[left + right] = '(';
            solve2_(left + 1, right, ans, s);
        }
        if (right < left)
        {
            s[left + right] = ')';
            solve2_(left, right + 1, ans, s);
        }
    }

    vector<string> solve2(int n)
    {
        vector<string> ans;
        string s(2 * n, ' ');
        solve2_(0, 0, ans, s);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);



    return 0;
}