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

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // 链表里的所有元素都要指向新建立的节点上
        // 一次遍历链表建next，然后存每个节点的地址。第二次遍历原链表再将random存好
        // random节点的val值就直接是那个节点的值了，并不是下标，这样不能找到random节点的地址

        if (head == nullptr)
            return nullptr;
        Node *cur = head;
        unordered_map<Node *, Node *> um;

        Node *npre = new Node(cur->val);
        um[cur] = npre;
        cur = cur->next;
        Node *root = npre;

        while (cur != nullptr)
        {
            Node *t = new Node(cur->val);
            npre->next = t;
            um[cur] = t;

            cur = cur->next;
            npre = npre->next;
        }

        cur = head;
        while (cur != nullptr)
        {
            um[cur]->random = um[cur->random];
            cur = cur->next;
        }

        return root;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);



    return 0;
}