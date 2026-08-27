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
    bool canPartition(vector<int>& nums) {
        int w = 0;
        for (int i : nums)
            w += i;
        if (w % 2)
            return false;
        w /= 2;

        int n = nums.size();
        vector<vector<bool>> d(n + 1, vector<bool>(w + 1));
        d[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                if (j >= nums[i - 1])
                    d[i][j] = d[i - 1][j - nums[i - 1]] || d[i - 1][j];
                else
                    d[i][j] = d[i - 1][j];
            }
        }

        return d[n][w];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    

    return 0;
}