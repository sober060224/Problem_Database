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
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] >= nums[0])
                l = mid + 1;
            else
                r = mid;
        }

        if (nums[l] > nums[0])
            return nums[0];
        return nums[l];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> nums = {3, 1, 2};
    Solution s;
    cout << s.findMin(nums);

    return 0;
}