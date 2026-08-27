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
        ans = max(ans, left + right + root->val);

        return max(max(left, right) + root->val, 0);
    }

    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution s;
    cout << s.maxPathSum(root);

    return 0;
}