#include <bits/stdc++.h>
using namespace std;

int board[200][200];
int vis[200][200];
int n, r1, r2, c1, c2;
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};

bool OOB(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return true;
    return false;
}

int bfs(int sx, int sy, int ex, int ey)
{
    queue<pair<int, int>> q;
    vis[sx][sy] = 1;
    q.push({sx, sy});
    while (q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (x == ex && y == ey)
        {
            return vis[x][y] - 1;
        }

        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (vis[nx][ny] || OOB(nx, ny))
                continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> r1 >> c1 >> r2 >> c2;

    cout << bfs(r1, c1, r2, c2);
}