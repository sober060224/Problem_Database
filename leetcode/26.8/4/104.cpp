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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int dfs(TreeNode *root, int &ans)
    {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left, ans), right = dfs(root->right, ans);
        ans = max(ans, max(left, right) + 1);

        return max(left, right) + 1;
    }

    int maxDepth(TreeNode *root)
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}