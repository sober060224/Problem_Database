#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define ll long long

void Init(std::vector<std::vector<int>> &dis, int n, bool &ok,
          std::vector<std::string> &river, int &l, int &r,
          std::deque<std::pair<int, int>> &d);

void showve(vector<string> &a)
{
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void showde(deque<pair<int, int>> d)
{
    while (!d.empty())
    {
        cout << d.front().first << ' ' << d.front().second << endl;
        d.pop_front();
    }
    cout << "-------------------" << endl;
}

void solve(vector<string> &river)
{
    // river 1-index river[i] 0-index
    int n = river[1].size(), l = 0, r = 0;
    deque<pair<int, int>> d;
    vector<vector<int>> dis(3, vector<int>(n, INT_MAX));
    vector<int> dx = {-1, 1, 0}, dy = {0, 0, 1};
    bool ok = true;
    vector<vector<bool>> visited(3, vector<bool>(n, false));
    Init(dis, n, ok, river, l, r, d);
    if (d.empty())
    {
        cout << 0;
        return;
    }

    while (!d.empty())
    {
        auto t = d.front();
        int x = t.first, y = t.second;
        d.pop_front();
        if (visited[x][y])
            continue;
        visited[x][y] = true;
        for (int i = 0; i < 3; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], w = river[nx][ny] == '.' ? 1 : 0;
            if (nx < 1 || nx > 2 || ny > r || dis[x][y] + w >= dis[nx][ny])
                continue;
            dis[nx][ny] = dis[x][y] + w;
            if (!w)
                d.push_front({nx, ny});
            else
                d.push_back({nx, ny});
        }
    }

    cout << min(dis[1][r], dis[2][r]);
}

void Init(vector<vector<int>> &dis, int n, bool &ok, std::vector<std::string> &river, int &l, int &r, std::deque<std::pair<int, int>> &d)
{
    for (int i = 0; i < n; i++)
    {
        if (ok && (river[1][i] == '#' || river[2][i] == '#'))
        {
            l = i;
            r = i;
            ok = false;
            if (river[1][i] == '#')
            {
                d.push_back({1, i});
                dis[1][i] = 0;
                continue;
            }
            d.push_back({2, i});
            dis[2][i] = 0;
        }
        if (!ok && (river[1][i] == '#' || river[2][i] == '#'))
            r = i;
    }
}
void test()
{
    vector<string> river = {"",
                            ".##.....#",
                            ".#.#.#..."};
    int l, r, n = river[1].size();
    deque<pair<int, int>> d;
    vector<vector<int>> dis(3, vector<int>(n, INT_MAX));
    bool ok = true;
    Init(dis, n, ok, river, l, r, d);
}

int main()
{
    // auto start = high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // test();
    // srand((unsigned int)time(nullptr));
    // string s = ".#";
    vector<string> river(3);
    for (int i = 1; i <= 2; i++)
        cin >> river[i];

    solve(river);

    // for (int i = 1; i <= 1e6; i++)
    // {
    //     river[1][i] = s[rand() % 2];
    //     river[2][i] = s[rand() % 2];
    // }
    // showve(river[1]);
    // showve(river[2]);
    // auto end = high_resolution_clock::now();
    // duration<double, milli> ms = end - start;
    // cout << ms.count() << "ms" << endl;

    return 0;
}