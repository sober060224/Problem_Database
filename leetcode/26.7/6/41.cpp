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
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); i++)
            us.insert(nums[i]);

        for (int i = 1; i < 1e6; i++)
            if (us.find(i) == us.end())
                return i;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    

    return 0;
}