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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode*> q;
        if (root == nullptr)
            return {};
        q.push(root);
        vector<vector<int>> ans;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> t;

            for (int i = 0; i < n; i++)
            {
                auto x = q.front();
                t.push_back(x->val);
                q.pop();

                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }

            ans.push_back(t);
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