#include <iostream>
#include <vector>
#define int long long
using namespace std;

string S;
char c1, c2;
int k;
vector<int> pos_c1, pos_c2;

signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> S >> c1 >> c2;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == c1) pos_c1.push_back(i);
        if (S[i] == c2) pos_c2.push_back(i);
    }
    int ans = 0;
    for (auto it : pos_c1) {
        ans += pos_c2.end() - lower_bound(pos_c2.begin(), pos_c2.end(), it + k - 1);
    }

    cout << ans;

    return 0;
}


