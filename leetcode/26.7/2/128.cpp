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
    int longestConsecutive(vector<int> &nums)
    {
        // 只需要随时访问首尾元素，deque？只需要返回长度
        // 哈希能不能做？
        // 服了，感觉像是数学证明一样
        unordered_set<int> us;
        for (int &i : nums)
            us.insert(i);

        int ans = 0;

        // 不能遍历原数组，原数组有太多重复数字，会重复进入内层循环
        for (int i : us)
        {
            // 找得到前一个数就跳过，因为不是最优情况
            if (us.count(i - 1))
                continue;

            int l = 1, t = i;
            while (us.count(t + 1))
            {
                l++;
                t++;
            }
            ans = max(l, ans);
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