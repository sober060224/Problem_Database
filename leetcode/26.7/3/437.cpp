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
    unordered_map<long long, int> um = {{0, 1}};

    // 两层循环遍历树
    int rootSum(TreeNode *root, long long targetSum)
    {
        if (!root)
            return 0;

        int sum = 0;
        if (root->val == targetSum)
            sum++;

        sum += rootSum(root->left, targetSum - root->val);
        sum += rootSum(root->right, targetSum - root->val);
        return sum;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;

        int sum = rootSum(root, targetSum);
        sum += pathSum(root->left, targetSum);
        sum += pathSum(root->right, targetSum);

        return sum;
    }

    // 一层循环利用哈希表快速找值, a[j] - a[i - 1] = target, a[i - 1] = a[j] - target
    int dfs(TreeNode *root, int targetSum, long long prefix)
    {
        if (!root)
            return 0;

        prefix += root->val;
        // 必须ans放在前面，否则会出现只有一个值，target=0也算成一种路径情况
        int ans = um[prefix - targetSum];
        
        um[prefix]++;
        ans += dfs(root->left, targetSum, prefix);
        ans += dfs(root->right, targetSum, prefix);
        um[prefix]--;

        return ans;
    }

    int solve2(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum, 0);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}