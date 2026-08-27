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
    int maxProfit(vector<int>& prices) {
        int l = 0, ans = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[l])
                ans = max(ans, prices[i] - prices[l]);
            else
                l = i;
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