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
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n, INT_MAX);
        d[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; i + j < n && j <= nums[i]; j++)
                d[i + j] = min(d[i + j], d[i] + 1);
        }

        return d[n - 1];
    }

    // 遍历可到达的位置时记录可到达的最远位置，到了不可到达的位置前一个位置时去到可到达的最远位置，并更新答案
    int solve(vector<int> &nums)
    {
        int n = nums.size(), cnt = 0, pre = 0, cur = INT_MIN;
        vector<int> d(n);

        for (int i = 0; i < n - 1; i++)
        {
            cur = max(cur, i + nums[i]);
            if (i == pre)
            {
                pre = cur;
                cnt++;
            }
        }

        return cnt;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    

    return 0;
}