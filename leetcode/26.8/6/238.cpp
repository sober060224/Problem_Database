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
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size(), num = 1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            num *= nums[i];

        vector<int> prefix(n, 1), suffix(n, 1);
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i + 1];

        for (int i = 0; i < n; i++)
            ans[i] = prefix[i] * suffix[i];

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}