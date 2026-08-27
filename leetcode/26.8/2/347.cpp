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
    int count, val;
    Node(int count, int val) : count(count), val(val) {}
    bool operator<(const Node &other) const
    {
        return count < other.count;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 好像优先队列也行吧，懒处理那样应该可以
        // 多一个状态哈希表，记录频率，和哈希表不同才清除
        // 一次循环将所有值都存进哈希表里面，值和出现次数对应起来
        // 同时一直将值和出现次数也放进优先队列里面
        // 感觉要能快速访问值和访问、修改出现次数
        unordered_map<int, int> um;
        priority_queue<Node> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            um[nums[i]]++;
            pq.push(Node(um[nums[i]], nums[i]));
        }

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().val);
            pq.pop();

            while (!pq.empty() && pq.top().count != um[pq.top().val])
                pq.pop();
        }

        // while (!pq.empty())
        // {
        //     cout << pq.top().count << ' ' << pq.top().val << endl;
        //     pq.pop();
        // }
        // cout << "---------------" << endl;
        // cout << um[1] << endl << "----------------------" << endl;
        // for (auto t : um)
        //     cout << t.first << ' ' << t.second << endl;

        return ans;
    }

    // 题目保证答案唯一，不会出现k = 1，但是有两个出现次数相同的情况
    vector<int> solve(vector<int> &nums, int k)
    {
        vector<int> ans;
        // insert不会插入空列表
        unordered_map<int, int> um;
        int cnt = INT_MIN;
        for (int i : nums)
        {
            um[i]++;
            cnt = max(um[i], cnt);
        }

        vector<vector<int>> buckets(cnt + 1);
        for (auto t : um)
            buckets[t.second].push_back(t.first);

        for (int i = cnt; ans.size() < k; i--)
            ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution s;
    vector<int> t = s.topKFrequent(nums, k);
    showve(t);

    return 0;
}