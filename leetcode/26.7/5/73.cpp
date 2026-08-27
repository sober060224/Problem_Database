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
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> x(m, false), y(n, false);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!matrix[i][j])
                    x[i] = y[j] = true;
            }
        }

        for (int i = 0; i < m; i++)
            if (x[i])
                for (int j = 0; j < n; j++)
                    matrix[i][j] = 0;

        for (int j = 0; j < n; j++)
            if (y[j])
                for (int i = 0; i < m; i++)
                    matrix[i][j] = 0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}