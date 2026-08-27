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
    bool canJump(vector<int> &nums)
    {
        // 感觉可以双重循环找0的位置，然后往前看有没有一个下标能超过0和这个下标长度的值，有就继续找，没有就返回false
        // showve(nums);
        int n = nums.size();

        // 刚好最后一个位置
        // for (int i = 0; i < n; i++)
        // {
        //     if (nums[i] == n - i - 1)
        //         return true;
        // }

        // 比最后一个位置长
        for (int i = 0; i < n; i++)
        {
            // cout << nums[i] << endl;
            if (nums[i] != 0)
                continue;

            // ok = false说明一直找不到
            bool ok = false;
            for (int j = 0; j < i; j++)
            {
                // cout << nums[j] << ' ' << i - j << endl;
                if (nums[j] > i - j)
                {
                    ok = true;
                    break;
                }
            }

            if (!ok && i != n - 1)
                return false;
        }

        return true;
    }

    bool solve2(vector<int> &nums)
    {
        int t = 0;
        for (int i = 0 ; i < nums.size(); i++)
        {
            if (t < i) 
                return false;
            t = max(t, i + nums[i]);
        }
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> nums = {3, 2, 1, 0, 4};
    Solution s;
    s.canJump(nums);

    return 0;
}