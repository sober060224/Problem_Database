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

    // 从最左侧开始，每天长高1厘米
    // 一开始都是0，要知道每棵树最高长到多高
    // 差分？每次到了位置都会修剪到0, n <= 10^4
    // n^2
    // 一开始从最左侧开始，每天向右，到最右向左
    // 到最左向右
    // 每次爱丽丝都会在晚上将当前位置变为0，所以一开始灌木都是1
    // 先长大，后修建，只有可能在长大的时候能得到最大值
    // 像是在找规律？数学吧
    // 模拟？好像是固定的
    // 最边边那两个就是n - i的两倍？
    // 两边对应的值都是相同的，只要找到左边值就能找到所有值
    // 好像是n - i和i - 1取最大值的两倍
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << max(n - i, i - 1) * 2 << endl;

    return 0;
}