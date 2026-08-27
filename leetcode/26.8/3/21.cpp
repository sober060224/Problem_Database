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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy;         // 用哨兵节点简化代码逻辑
        ListNode *cur = &dummy; // cur 指向新链表的末尾
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1; // 把 list1 加到新链表中
                list1 = list1->next;
            }
            else
            {                      // 注：相等的情况加哪个节点都是可以的
                cur->next = list2; // 把 list2 加到新链表中
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2; // 拼接剩余链表
        return dummy.next;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // 创建哨兵节点，避免单独处理头结点和链表为空
        // 必须初始化到栈上，指针要初始化，野指针不能访问
        ListNode root, *cur = &root;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        // 直接用三目运算符简化表达式，因为只有这两种情况在最后
        cur->next = list1 ? list1 : list2;

        return root.next;
    }

    ListNode *solve2(ListNode *list1, ListNode *list2)
    {
        ListNode *head;

        // 有一个为空，两个为空，正常
        if (!list1 && list2)
            return list2;
        else if (list1 && !list2)
            return list1;
        else if (!list1 && !list2)
            return nullptr;
        else
        {
            if (list1->val < list2->val)
            {
                head = list1;
                list1 = list1->next;
            }
            else
            {
                head = list2;
                list2 = list2->next;
            }
        }
        ListNode *root = head;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                head->next = list1;
                head = list1;
                list1 = list1->next;
            }
            else
            {
                head->next = list2;
                head = list2;
                list2 = list2->next;
            }
        }

        // 链表可以直接用下一个节点表示后面的所有节点，不需要一步步遍历下去了
        if (list1)
            head->next = list1;
        if (list2)
            head->next = list2;
        // while (list1)
        // {
        //     head->next = list1;
        //     head = list1;
        //     list1 = list1->next;
        // }
        // while (list2)
        // {
        //     head->next = list2;
        //     head = list2;
        //     list2 = list2->next;
        // }

        return root;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}