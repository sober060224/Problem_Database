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
    bool dfs(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr || right == nullptr)
            return left == right;

        return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        // 感觉用二进制编码一下，最多有十层就是2的十次方，但是int4字节32位能有32次方
        // 整棵树遍历完之后看看每个数有没有和这个数异或之后结果的值就说明是不是轴对称，用哈希表存每个节点
        // 不一定最多10层啊，又不是平衡二叉树。
        return dfs(root->left, root->right);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}