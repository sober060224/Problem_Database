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
    void dfs(vector<int> &nums, int index, vector<int> &t, vector<vector<int>> &ans)
    {
        int n = nums.size();
        if (index >= n)
            return;

        for (int i = index; i < n; i++)
        {
            t.push_back(nums[i]);
            ans.push_back(t);
            dfs(nums, i + 1, t, ans);
            t.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        ans.push_back({});
        vector<int> t;
        dfs(nums, 0, t, ans);

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}