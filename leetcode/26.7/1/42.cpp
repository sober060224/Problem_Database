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

void show(stack<int> s)
{
    while(!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

class Solution
{
public:
    // 找到区间的左右边界然后计算能装的水量这样？
    // 计算要装的水量也麻烦啊……两个步骤都麻烦
    // 找到两个开始下降的地方，计算能装的水量在遍历的时候就开始计算？都不知道最后找到的第二个边界是比第一个边界高还是低
    // 可以看每个柱子能装的水量来计算总共能装的水量，感觉最关键。
    // 双指针、前缀和预处理、单调栈
    // 单调栈每次找到一个比单调递减栈大的值就反复计算区间值，并不是一下子将整个的可能值算出来，而是一层层计算
    
    // 前缀和预处理
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> prefix(n + 1), suffix(n + 1);
        prefix[0] = height[0], suffix[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
            prefix[i] = max(prefix[i - 1], height[i]);

        for (int i = n - 2; i >= 0; i--)
            suffix[i] = max(suffix[i + 1], height[i]);

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += (min(prefix[i], suffix[i]) - height[i]);
        
        return ans;
    }

    // 双指针
    // 只看从左边来的最大值和从右边来的最大值最后就可以一步步计算出最终值
    // 处理每个位置可以接的水只需要有一个方向比另一个方向的最大值小就可以移动位置处理这个位置的水
    // 虽然处理的只是一层的水，并不是这个位置最后能装的水，但是算法结束的时候能得出最后能装的所有水
    // 因为算法是一层层水算上去的
    // 相当于竖着找水量
    int solve2(vector<int> &height)
    {
        int n = height.size(), ans = 0, l = 0, r = n - 1, left = INT_MIN, right = INT_MIN;

        while (l < r)
        {
            left = max(left, height[l]), right = max(right, height[r]);
            if (left < right)
            {
                ans += (left - height[l]);
                l++;
            }
            else
            {
                ans += (right - height[r]);
                r--;
            }
        }

        return ans;
    }

    // 单调栈
    // 能访问最近更小的元素
    // 相当于横着找水量
    int solve3(vector<int> &height)
    {
        stack<int> s;
        int ans = 0;

        for (int i = 0; i < height.size(); i++)
        {
            // show(s);

            while(!s.empty() && height[s.top()] < height[i])
            {
                int top = s.top();
                s.pop();
                if (s.empty())
                    break;
                int next = s.top();

                ans += (min(height[i], height[next]) - height[top]) * (i - next - 1);
            }
            s.push(i);
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    cout << s.solve3(height);

    return 0;
}