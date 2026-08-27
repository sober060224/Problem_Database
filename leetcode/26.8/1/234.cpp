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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> a;
        while (head != nullptr)
        {
            a.push_back(head->val);
            head = head->next;
        }

        for (int i = 0; i < a.size() / 2; i++)
        {
            if (a[i] != a[a.size() - i - 1])
                return false;
        }

        return true;
    }

    bool dfs(ListNode *right, ListNode *&left)
    {
        if (right->next && !dfs(right->next, left))
            return false;

        if (left->val != right->val)
            return false;

        left = left->next;
        return true;
    }

    bool solve(ListNode *head)
    {
        ListNode *cur = head;
        return dfs(head, cur);
    }

    bool solve2(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *pre = nullptr;
        while (slow)
        {
            ListNode *next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        while (pre)
        {
            if (pre->val != head->val)
                return false;
            pre = pre->next;
            head = head->next;
        }

        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    Solution s;
    ListNode *head = new ListNode(1), *t = head;
    head->next = new ListNode(2);
    head = head->next;
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(4);
    head = head->next;
    head->next = new ListNode(5);
    s.solve2(t);

    return 0;
}