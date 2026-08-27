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

void show(TreeNode *root)
{
    if (!root)   
        return;

    show(root->left);
    cout << root->val;
    show(root->right);
}

class Solution
{
public:
    TreeNode *head = nullptr;

    void flatten(TreeNode *root)
    {
        // 直接进行头插法遍历组成一个链表会丢失节点，反着遍历就行，从下往上一个个遍历
        if (!root)
            return;

        // nlr, rln
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = head;
        head = root;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    TreeNode *root = new TreeNode(1);
    TreeNode *t = root;
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root = root->left;
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root = t;
    root = root->right;
    root->right = new TreeNode(6);
    root = t;
    Solution s;
    s.flatten(root);
    show(root);
    cout << endl << root->right->val;

    return 0;
}