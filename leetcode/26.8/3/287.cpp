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
    int findDuplicate(vector<int> &nums)
    {
        // 总共1+n个数，数组的大小n，里面的数除了0之外所有值都有
        // 下标[0, n-1], 值[1, n-1]
        // 二分找到一个值能比所有值小的次数大过自己，因为<=的话就有可能是小过他的值比较少，然后大过他的值比较多，也就是重复值出现在了更大的数上
        // >的话就说明[1,mid]的值里面出现了重复的数，有可能枚举的这个数就是答案
        // 二分答案，二分枚举答案
        int l = 1, r = nums.size() - 1, ans;

        while (l <= r)
        {
            int mid = (l + r) / 2, cnt = 0;
            for (int i = 0; i < nums.size(); i++)
                if (nums[i] <= mid)
                    cnt++;

            if (cnt <= mid)
                l = mid + 1;
            else
            {
                r = mid - 1;
                ans = mid;
            }
        }

        return ans;
    }

    // 二进制解法是从二进制的视角看每个数的值，如果有一个数在某一位上重复了这个位就会比没有重复的时候多
    int solve2(vector<int> &nums)
    {
        int bit = 31, n = nums.size();
        while (!((n - 1) >> bit))
            bit--;

        int ans = 0;
        for (int i = 0; i <= bit; i++)
        {
            int x = 0, y = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] & (1 << i))
                    x++;
                if (j >= 1 && (j & (1 << i)))
                    y++;
            }

            if (x > y)
                ans |= (1 << i);
        }

        return ans;
    }

    // Floyd判图、基环树
    int solve3(vector<int> &nums)
    {
        int slow = 0, fast = 0;

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}