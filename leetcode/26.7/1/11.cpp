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

class Solution
{
public:
    int maxArea(vector<int>& height) {
        // 两层循环遍历所有区间可以找到最大水量
        // 让区间能容纳的水量最大，长和高乘积最大
        // 仍然是两层循环的思路，但是循环的思路变了
        // 一开始是从开始到结尾的区间长度，两层循环就是枚举两个指针遍历所有区间情况的水量
        // 因为答案要找最大水量，所以每次循环都找到第二层循环里面的最大值就可以了
        // 利用双指针，如果有一个指针的值比较小就移动那个值，就可以将另一个指针不动，另一个指针一直动的所有情况全部考虑完整，将右指针固定的情况所有遍历完
        int l = 0, r = height.size() - 1, ans = INT_MIN;
        
        while (l < r)
        {
            ans = max(min(height[l], height[r]) * (r - l), ans);
            if (height[l] > height[r])
                r--;
            else
                l++;
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    

    return 0;
}