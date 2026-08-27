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
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> index(26);
        for (int i = 0; i < n; i++)
            index[s[i] - 'a'] = max(index[s[i] - 'a'], i);

        int start = 0, end = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            end = max(end, index[s[i] - 'a']);
            if (i == end)
            {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
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