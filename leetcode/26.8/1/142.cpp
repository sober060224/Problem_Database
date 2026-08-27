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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // // 两层循环看是否入环

        // // 第一层循环看入环的第一个节点
        // while (head != nullptr)
        // {
        //     // 第一次出现两次地址相同的就是那个
        //     // 第二层循环看是否存在环
        //     // 存在环且和当前节点相同就返回这个节点
        //     // 如果不存在环，能到nullptr就不存在环

        //     // 快速判断当前节点最后会不会到这个节点
        //     ListNode *next = head;
        //     unordered_set<ListNode *> us;
        //     while (next && us.find(next) == us.end())
        //     {
        //         us.insert(next);
        //         next = next->next;
        //     }

        //     // 退出循环是不存在环，到了入环第一个节点，当前节点不是第一个节点，是第一个节点
        //     if (!next)
        //         return nullptr;
        //     if (next == head)
        //         return head;

        //     head = head->next;
        // }

        unordered_set<ListNode *> us;
        while (head && us.find(head) == us.end())
        {
            us.insert(head);
            head = head->next;
        }

        if (!head)
            return nullptr;
        return head;
    }

    ListNode *solve(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (head != slow)
                {
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    ListNode *root = new ListNode(3), *head = root;
    root->next = new ListNode(2);
    root = root->next;
    ListNode *t = root;
    root->next = new ListNode(0);
    root = root->next;
    root->next = new ListNode(-4);
    root = root->next;
    root->next = t;
    Solution s;
    cout << s.detectCycle(head)->val;

    return 0;
}