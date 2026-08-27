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
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> pre;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> t;
            t.push_back(1);
            if (i > 1)
            {
                for (int j = 1; j < i; j++)
                {
                    t.push_back(pre[j - 1] + pre[j]);
                }
            }
            if (i > 0)
                t.push_back(1);
            pre = t;
            ans.push_back(t);
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