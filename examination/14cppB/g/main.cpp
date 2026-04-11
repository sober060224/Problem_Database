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

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // 好像是将是这个字符的下标记录下来，然后找比长度大的两个下标
    // 用集合存起来吧，每次都二分找长度更大的，差不多
    int k;
    string s;
    char c1, c2;
    cin >> k >> s >> c1 >> c2;
    // 双指针好像也行，双指针应该好一点，维护区间性质这样的
    // 算了吧，都不能随机访问
    // 好像直接用数组存起来双指针就搞定了，都不用他妈的集合
    // 不行吧，好像是没有单调性
    // 集合迭代器好像又不能顺序访问那样的那每次二分找到之后都要循环到最后一个元素吗
    // 这好像都超时了
    // 不用集合存，直接两个数组存都行了，本来就是递增的
    // 存起来然后每个c1下标找c2下标c1 - c2 + 1 = K, c1 = c2 + k - 1
    // 找到c2之后就是加起来了
    vector<int> index1, index2;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c1)
            index1.push_back(i);
        if (s[i] == c2)
            index2.push_back(i);
    }
    // showve(index1);
    // showve(index2);
    // cout << index2.end() - index2.begin() << endl;
    // cout << index2.size() << endl;
    ll cnt = 0;
    for (int i = 0; i < index1.size(); i++)
    {
        // 还要看看到底有没有这个地方
        auto it = lower_bound(index2.begin(), index2.end(), index1[i] + k - 1);
        cnt += index2.size() - (it - index2.begin());
    }
    cout << cnt;

    return 0;
}