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
    void dfs(vector<int> &nums, int index, vector<int> &arr, vector<vector<int>> &ans, vector<bool> &visited)
    {
        int n = nums.size();
        if (index >= n)
        {
            ans.push_back(arr);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            visited[i] = true;
            arr[index] = nums[i];
            dfs(nums, index + 1, arr, ans, visited);
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> arr(n);
        vector<bool> visited(n, false);
        dfs(nums, 0, arr, ans, visited);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}