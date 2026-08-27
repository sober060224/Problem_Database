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
    // 要找中位数只要找到一堆数字的最大值比另一堆数字的最小值更小就行了
    // 同时两堆数字的个数必须相同
    // 只要找到这样的两堆数字就行了，不需要管是怎么找到的

    // 双指针
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            swap(nums1, nums2);

        nums1.insert(nums1.begin(), INT_MIN);
        nums2.insert(nums2.begin(), INT_MIN);
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);

        int i = 0, j = (m + n + 1) / 2;

        while (max(nums1[i], nums2[j]) > min(nums1[i + 1], nums2[j + 1]))
        {
            i++;
            j--;
        }
        // 目标是找到max(nums1[i], nums2[j]) <= min(nums1[i + 1], nums2[j + 1])
        // 因为最大的都要比右边最小的小，所以左边所有的数都要比右边的小
        // 等价于nums1[i] <= nums2[j + 1], nums2[j] <= nums1[i + 1], nums1[i + 1] >= nums2[j]
        // 找到同时满足这两个条件的位置

        if ((m + n) % 2)
            return max(nums1[i], nums2[j]);
        else
            return (max(nums1[i], nums2[j]) + min(nums1[i + 1], nums2[j + 1])) / 2.0;
    }

    // 二分
    double solve(vector<int> &nums1, vector<int> &nums2)
    {
        // i越小nums1[i] <= nums2[j + 1]越能成立，i越大越不成立，但是nums1[i + 1] >= nums2[j]越能成立
        // 用二分找第一个数组的分界线i
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            swap(nums1, nums2);
        m = nums1.size(), n = nums2.size();
        
        int left = 0, right = m - 1, ans = -1;
        while (left <= right)
        {
            // 把下标转换成长度来看相比长度转换成下标更方便
            int i = (left + right) / 2, j = (m + n + 1) / 2 - 2 - i;
            if (nums1[i] <= nums2[j + 1])
            {
                left = i + 1;
                ans = i;
            }
            else
                right = i - 1;
        }

        int i = ans, j = (m + n + 1) / 2 - 2 - i, a, b, c, d;
        a = i >= 0 ? nums1[i] : INT_MIN, b = j >= 0 ? nums2[j] : INT_MIN;
        c = i < m - 1 ? nums1[i + 1] : INT_MAX, d = j < n - 1? nums2[j + 1] : INT_MAX;
        return (m + n) % 2 ? max(a, b) : ((max(a, b) + min(c, d)) / 2.0);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> a = {1, 2}, b = {3, 4};
    Solution s;
    cout << s.solve(a, b);

    return 0;
}