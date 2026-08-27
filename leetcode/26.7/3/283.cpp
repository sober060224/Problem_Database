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
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size(), l = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                l++;
        }

        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());

        for (int i = 0; i < l; i++)
            nums.push_back(0);
    }

    void solve2(vector<int> &nums)
    {
        // 双指针
        int l = -1, r = 0, n = nums.size();

        while (r < n)
        {
            if (nums[r] != 0)
            {
                swap(nums[l + 1], nums[r]);
                l++;
            }
            r++;
        }
    }

    void solve3(vector<int> &nums)
    {
        int l = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                swap(nums[i], nums[l++]);
        }
        for (int i = l + 1; i < nums.size(); i++)
            nums[i] = 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> nums = {0, 1, 0, 3, 12};
    Solution s;
    s.solve3(nums);
    showve(nums);

    return 0;
}