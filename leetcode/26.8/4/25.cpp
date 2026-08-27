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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int sum = 0;
        ListNode *t = head;
        while (t)
        {
            sum++;
            t = t->next;
        }

        int cnt = sum / k;
        ListNode *p0 = new ListNode(0, head);

        // 每一组的第一个最后才给next赋值，其他的正常倒转
        // 倒转之后cur到了下一组的第一个节点，pre是当前组的第一个节点
        // 将每一组的第一个的前一个节点p0的next指向pre，第一个节点next指向cur，p0赋值成pre
        for (int i = 0; i < cnt; i++)
        {
            ListNode *pre = p0->next, *cur = pre->next;
            for (int j = 0; j < k - 1; j++)
            {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            if (i == 0)
                head = pre;
            p0->next->next = cur;
            ListNode *t = p0->next;
            p0->next = pre;
            p0 = t;
        }

        return head;
    }
};

// 好像创建这个临时变量，然后就会一直在那里不变，一直更改的是一开始指向他的指针，指向他的指针可以更改他的值next指针
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // 统计节点个数
        int n = 0;
        for (ListNode *cur = head; cur; cur = cur->next)
        {
            n++;
        }

        ListNode dummy(0, head);
        ListNode *last_tail = &dummy; // 上一组翻转后的尾节点

        // k 个一组处理
        for (; n >= k; n -= k)
        {
            ListNode *pre = nullptr;
            ListNode *cur = last_tail->next;
            for (int i = 0; i < k; i++)
            { // 同 92 题
                ListNode *nxt = cur->next;
                cur->next = pre; // 每次循环只修改一个 next，方便大家理解
                pre = cur;
                cur = nxt;
            }

            // 请结合视频中的图理解
            // 翻转后：
            // pre 是当前组的头节点
            // cur 是下一组的起始节点
            // last_tail 是上一组的尾节点
            // last_tail->next 是当前组的尾节点
            ListNode *tail = last_tail->next;
            tail->next = cur;      // 当前组的尾节点指向下一组的起始节点
            last_tail->next = pre; // 上一组的尾节点指向当前组的头节点
            last_tail = tail;
        }

        return dummy.next;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}