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
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // 将每个字符串都排序一下，将相同的加进同一个哈希表里面
        unordered_map<string, vector<string>> um;
        for (string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            um[t].push_back(s);
        }

        // 最后将所有结果返回就行
        vector<vector<string>> ans;
        for (auto t : um)
            ans.push_back(t.second);
        return ans;
    }
};

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}