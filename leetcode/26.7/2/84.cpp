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
    int largestRectangleArea(vector<int> &heights)
    {
        // 两层循环，枚举两个边界，定下最短高度，算出矩形面积
        int n = heights.size();
        vector<int> left(n + 1), right(n + 1);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[i] <= heights[s.top()])
                s.pop();

            if (s.empty())
                left[i] = -1;
            else
                left[i] = s.top();

            s.push(i);
        }

        s = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[i] <= heights[s.top()])
                s.pop();

            if (s.empty())
                right[i] = n;
            else
                right[i] = s.top();

            s.push(i);
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> heights = {2, 4};
    Solution s;
    cout << s.largestRectangleArea(heights);

    return 0;
}