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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;

        for (int i = 0; i < nums.size(); i++)
        {
            if (!q.empty() && q.front() <= i - k)
                q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
                
            q.push_back(i);

            if (i + 1 >= k)
                ans.push_back(nums[q.front()]);
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