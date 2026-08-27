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
    set<vector<int>> s;

    void dfs(vector<int> &candidates, vector<int> des, int target, vector<vector<int>> &ans)
    {
        int n = candidates.size();
        if (!target)
        {
            sort(des.begin(), des.end());
            if (s.find(des) == s.end())
            {
                ans.push_back(des);
                s.insert(des);
            }

            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (candidates[i] > target)
                return;
            des.push_back(candidates[i]);
            dfs(candidates, des, target - candidates[i], ans);
            des.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // 和顺序无关
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        dfs(candidates, {}, target, ans);
        return ans;
    }

    void sdfs(vector<int> &candidates, int index, int target, vector<vector<int>> &ans, vector<int> des)
    {
        int n = candidates.size();
        if (!target)
        {
            ans.push_back(des);
            return;
        }

        for (int i = index; i < n; i++)
        {
            if (candidates[i] > target)
                return;
            des.push_back(candidates[i]);
            sdfs(candidates, i, target - candidates[i], ans, des);
            des.pop_back();
        }
    }

    vector<vector<int>> solve2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        sdfs(candidates, 0, target, ans, {});
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans;
    Solution s;
    ans = s.combinationSum(candidates, target);

    return 0;
}