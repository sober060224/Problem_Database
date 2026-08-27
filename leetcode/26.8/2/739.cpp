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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;

        // 也可以从左往右记录最近元素，有一个更大的元素就说明是下一个更高温度
        // 这个是从右往左，每个元素都删除栈元素直到找到下一个更高温度
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
                s.pop();

            if (s.empty())
                ans[i] = 0;
            else
                ans[i] = s.top() - i;

            s.push(i);
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