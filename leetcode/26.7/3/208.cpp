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

// 前缀串感觉是可以直接用哈希集合存？
// 前缀和完整字符串分别用不同的哈希集合
// abc, abd, abe
class Node
{
public:
    Node *son[26];
    bool end = false;
};

class Trie
{
public:
    unordered_set<string> us1, us2;
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        us1.insert(word);

        string t;
        for (int i = 0; i < word.size(); i++)
        {
            t.push_back(word[i]);
            us2.insert(t);
        }
    }

    void solve2(string word)
    {
        Node *cur = root;

        for (char c : word)
        {
            int index = c - 'a';
            if (cur->son[index] == nullptr)
                cur->son[index] = new Node();
            cur = cur->son[index];
        }

        cur->end = true;
    }

    bool search(string word)
    {
        if (us1.find(word) != us1.end())
            return true;
        else
            return false;
    }

    bool search2(string word)
    {
        Node *cur = root;

        for (char c : word)
        {
            int index = c - 'a';
            if (cur->son[index] == nullptr)
                return false;
            cur = cur->son[index];
        }

        if (cur->end)
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        if (us2.find(prefix) != us2.end())
            return true;
        else
            return false;
    }

    bool start2(string prefix)
    {
        Node *cur = root;

        for (char c : prefix)
        {
            int index = c - 'a';
            if (cur->son[index] == nullptr)
                return false;
            cur = cur->son[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Solution
{
public:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    return 0;
}