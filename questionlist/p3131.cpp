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

void test()
{
    srand((unsigned int)time(nullptr));
    int a = rand() % 1000, b = rand() % 1000, c = rand() % min(a, b);
    for (int i = 0; i < 10; i++)
        if ((a + b) % c != ((a % c) + (b % c)) % c)
            cout << "no" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // test();

    int n;
    cin >> n;
    vector<int> id(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        id[i] = (t + id[i - 1]) % 7;
    }
    // showve(id);

    // 区间查询10^4，id[i]，10^6
    // nlogn，找连续区间和是7的倍数的最大长度

    // // 枚举两个变量，剩下数字比答案还少就退出
    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    //     // 答案如果已经有k个奶牛是7的倍数了，那就要找比k更大的区间
    //     for (int j = i + ans; j <= n; j++)
    //         // cout << id[j] << ' ' << id[i - 1] << endl;
    //         if ((id[j] - id[i - 1]) % 7 == 0)
    //             ans = j - i + 1;
    // cout << ans;

    // 答案没有单调性，连存区间都不行
    // 前缀和有单调性，枚举一个变量，另一个变量二分找7的倍数下标，尽可能往大了找
    // for循环枚举左边界，找二分找当前左边界和n中间位置值(id[mid] - id[i]) % 7 == 0
    // 答案没有单调性啊，找取余执行不下去

    // (id[j] - id[i - 1]) % 7 == 0
    // id[j] % 7 == id[i - 1] % 7
    int ans = 0;
    // 注意初始化，可能从第一个数开始就是最大连续了
    // 初始值不能是0~n的数，否则会干扰求值
    vector<int> idx(7, -1);
    // 取余0的前缀和下标一定为0
    idx[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        // 如果这个值还没存过就将取余后的结果的下标存下去
        // idx[id[i]] = i;
        if (idx[id[i]] == -1)
            idx[id[i]] = i;
        // 存过了就计算结果值
        else
            ans = max(ans, i - idx[id[i]]);
        // showve(idx);
    }
    cout << ans;

    return 0;
}