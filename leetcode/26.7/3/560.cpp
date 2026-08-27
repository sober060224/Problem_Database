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
    int subarraySum(vector<int> &nums, int k)
    {
        // 子数组和，a[j] - a[i] = k, a[i] = a[j] - k
        int n = nums.size(), ans = 0;
        vector<int> prefix(n + 1);
        prefix[0] = nums[0];
        unordered_map<int, int> um;
        um[0] = 1;
        ans += um[prefix[0] - k];
        um[prefix[0]]++;

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
            ans += um[prefix[i] - k];
            um[prefix[i]]++;
            cout << "i = " << i << " ans = " << ans << endl;
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> nums = {1, 1, 1};
    int k = 2;
    Solution s;
    cout << s.subarraySum(nums, k);

    return 0;
}