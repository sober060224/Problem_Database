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
    TreeNode *dfs(vector<int> &preorder, int a, int b, vector<int> &inorder, int c, int d)
    {
        if (a > b || c > d)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[a]);
        if (a == b)
            return root;
        
        // 中序遍历根节点下标
        int i = c;
        for (; i <= d && inorder[i] != preorder[a]; i++);

        // 左右子树节点总数
        int l = i - c, r = d - i;
        root->left = dfs(preorder, a + 1, b - r, inorder, c, d - r - 1);
        root->right = dfs(preorder, a + l + 1, b, inorder, c + l + 1, d);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        return dfs(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> preorder = {1, 2}, inorder = {2, 1};
    Solution s;
    s.buildTree(preorder, inorder);

    return 0;
}