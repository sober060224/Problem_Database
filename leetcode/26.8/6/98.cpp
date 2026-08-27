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
    pair<long long, long long> dfs(TreeNode *root)
    {
        if (root == nullptr)
            return {LONG_LONG_MIN, LONG_LONG_MAX};
        auto left = dfs(root->left), right = dfs(root->right);
        long long big = max({left.first, right.first, (long long)root->val}), small = min({left.second, right.second, (long long)root->val});

        if (root->val <= left.first || root->val >= right.second)
            return {LONG_LONG_MAX, LONG_LONG_MIN};
        return {big, small};
    }

    // 要在遍历的同时记录是不是搜索树，不用在遍历结束后再特判
    bool isValidBST(TreeNode *root)
    {
        return dfs(root).first != LONG_LONG_MAX;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    

    return 0;
}