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
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size(), ans = INT_MIN;
        vector<int> MAX(n + 1), MIN(n + 1);
        MAX[0] = MIN[0] = nums[0];
        ans = max(ans, MAX[0]);

        for (int i = 1; i < n; i++)
        {
            MAX[i] = max({MAX[i - 1] * nums[i], MIN[i - 1] * nums[i], nums[i]});
            MIN[i] = min({MAX[i - 1] * nums[i], MIN[i - 1] * nums[i], nums[i]});
            ans = max(ans, MAX[i]);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);



    return 0;
}