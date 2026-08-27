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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *cur = head, *next = cur->next, *node = next->next;
        cur->next = swapPairs(node);
        next->next = cur;

        return next;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head = head->next;
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(4);
    ListNode *t = head;
    while (head != nullptr)
    {
        cout << head->val << endl;
        head = head->next;
    }
    Solution s;
    s.swapPairs(t);

    return 0;
}