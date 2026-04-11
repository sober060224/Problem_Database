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

// 从1开始dfs走，遇到边界就返回将visited还原，继续走？
// 不走了，认为这个方向不在闭合圈内，一直返回，换一个方向再走
// 只有在一开始递归进去的时候才是全方向走，别的时候都是朝着一个方向一直走
// 看看是不是闭合的，是闭合的就全方向走
// 那要递归进去才判断经不经过1？

// 如果能到达方阵边界就将visited全部还原，否则一直搜索，visited=true的地方就输出2
bool case01(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &visited)
{
    int n = matrix.size() - 1;

    // 上下左右
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

    // 遍历相邻状态，从1开始的搜索
    // 必须要一直经过0（不经过1），然后到达边界，就说明不在闭合圈内
    // 在闭合圈内就将visited设置成true
    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i], newy = y + dy[i];
        // 要对newx和newy合理性判断
        if (newx < 1 || newx > n || newy < 1 || newy > n)
            return false;
        // 不能经过1，也不能已经访问过了导致重复访问
        if (matrix[newx][newy] == 1 || visited[newx][newy] == 1 || visited[newx][newy] == 3)
            continue;
        visited[newx][newy] = 1;
        if (!case01(matrix, newx, newy, visited))
        {
            visited[newx][newy] = 3;
            return false;
        }
    }

    return true;
}
// 一直都走所有方向，只是不在闭合圈内就马上返回到一开始递归进去那里，然后走下一个方向
// 在闭合圈内就一直递归走
// visited = 0：没访问过，visited = 1：确定在闭合圈内，为2，visited = 2：访问过不是闭合圈内
// 没访问过的就就访问，确定在圈内的就跳过，不是圈内的就返回
// 不知道为什么就是错了，ai也找不出具体错误
bool solve(vector<vector<int>> &matrix, int x, int y, vector<vector<int>> &visited, bool start)
{
    int n = matrix.size() - 1;
    // 上下左右
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    
    // 一开始保证要走完所有方向，之后可以一直递归回去设置状态
    if (start)
    {
        // 一开始走保证能所有方向都能走完
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            // 一开始走错了还要走别的方向，走到已经访问过的也一样
            if (newx < 1 || newx > n || newy < 1 || newy > n || matrix[newx][newy] == 1 || visited[newx][newy] >= 1)
                continue;
            visited[newx][newy] = 1;
            // 走到闭合圈外就重新标记
            if (!solve(matrix, newx, newy, visited, false))
                visited[newx][newy] = 2;
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            // 走到边界说明不在闭合圈内，已经走过不在圈内的点也说明不在圈内
            if (newx < 1 || newx > n || newy < 1 || newy > n || visited[newx][newy] == 2)
                return false;
            if (matrix[newx][newy] == 1 || visited[newx][newy] == 1)
                continue;
            visited[newx][newy] = 1;
            // 返回true说明在闭合圈内，一直都走不到边界，而是被1包围住了
            // false说明走到了边界，这个方向不可行，返回到一开始递归的位置再重新开始
            if (!solve(matrix, newx, newy, visited, false))
            {
                visited[newx][newy] = 2;
                return false;
            }
        }
    }
    
    // 说明当前位置已经走完
    return true;
}
void test01()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
    // visited = 0：没访问过，visited = 1：确定在闭合圈内，为2，visited = 2：访问过不是闭合圈内
    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    cout << "-----------------------------" << endl;

    // dfs？
    // 无法到达方阵的边界，就认为这个 0 在闭合圈内
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (matrix[i][j] == 1)
                solve(matrix, i, j, visited, true);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j] != 1)
                cout << matrix[i][j] << ' ';
            else
                cout << 2 << ' ';
        }
        cout << endl;
    }
}

void dfs(vector<vector<int>> &matrix, int x, int y, vector<vector<bool>> &visited)
{
    int n = matrix.size() - 2;
    // 上下左右
    vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    for (int i = 0; i < 4; i++)
    {
        int newx = x + dx[i], newy = y + dy[i];
        // 矩形[0, n + 1]，不能访问1内和已访问过元素
        if (newx < 0 || newx > n + 1 || newy < 0 || newy > n + 1 || visited[newx][newy] || matrix[newx][newy] == 1)
            continue;
        visited[newx][newy] = true;
        dfs(matrix, newx, newy, visited);
    }
}
void test02()
{
    // 洪水填充
    int n;
    cin >> n;
    vector<vector<int>> matrix(n + 2, vector<int>(n + 2));
    vector<vector<bool>> visited(n + 2, vector<bool>(n + 2, false));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    dfs(matrix, 0, 0, visited);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!visited[i][j] && matrix[i][j] != 1)
                cout << 2 << ' ';
            else
                cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    // test01();
    test02();

    return 0;
}