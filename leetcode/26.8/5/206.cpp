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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = head, *pre = nullptr;

        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        dummy->next = pre;

        return dummy->next;
    }

    void dfs(ListNode *cur, ListNode *pre, ListNode *&head)
    {
        if (cur == nullptr)
        {
            head = pre;
            return;
        }

        dfs(cur->next, cur, head);
        cur->next = pre;
    }

    ListNode *solve(ListNode *head)
    {
        ListNode *h;
        dfs(head, nullptr, h);
        return h;
    }
};

class Solution
{
public:
    // 首先「递」到链表末尾，把末尾节点作为新链表的头节点 rev_head
    // 然后在「归」的过程中，把经过的节点依次插在新链表的末尾（尾插法）
    ListNode *reverseList(ListNode *head)
    {
        // 判断 head == nullptr 是为了兼容一开始链表就是空的情况
        if (head == nullptr || head->next == nullptr)
        {
            return head; // 链表末尾，即下面的 rev_head
        }
        auto rev_head = reverseList(head->next); // 「递」到链表末尾，拿到新链表的头节点
        ListNode *tail = head->next;             // 在「归」的过程中，head->next 就是新链表的末尾
        tail->next = head;                       // 把 head 插在新链表的末尾
        head->next = nullptr;                    // 如果不写这行，新链表的末尾两个节点成环，这俩节点互相指向对方
        return rev_head;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}