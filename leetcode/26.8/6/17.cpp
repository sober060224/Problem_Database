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
    // 用一个字符串数组记录每个数字代表的字符串
    void dfs(string digits, int index, string &s, vector<string> &ans)
    {
        int n = digits.size();
        if (index >= n)
        {
            ans.push_back(s);
            return;
        }

        int start = (digits[index] - '2') * 3;
        if (digits[index] == '8' || digits[index] == '9')
            start++;
        int end = 3;
        if (digits[index] == '7' || digits[index] == '9')
            end++;

        for (int i = 0; i < end; i++)
        {
            char c = 'a' + start + i;
            s[index] = c;
            dfs(digits, index + 1, s, ans);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();
        string s(n, ' ');
        vector<string> ans;
        dfs(digits, 0, s, ans);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    Solution s;
    string digits = "23";
    vector<string> ans = s.letterCombinations(digits);
    for (string s : ans)
        cout << s << endl;

    return 0;
}