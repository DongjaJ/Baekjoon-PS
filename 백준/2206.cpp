#include <bits/stdc++.h>
using namespace std;

char board[1000][1000];
int vis[1000][1000][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<tuple<int, int, int>> q;

int n, m;

int bfs()
{
    q.push({0, 0, 0});
    vis[0][0][0] = vis[0][0][1] = 1;
    while (!q.empty())
    {
        int x, y, b;
        tie(x, y, b) = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1)
            return vis[x][y][b];
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (board[nx][ny] == '0' && !vis[nx][ny][b])
            {
                vis[nx][ny][b] = vis[x][y][b] + 1;
                q.push({nx, ny, b});
            }

            if (board[nx][ny] == '1' && b == 0)
            {
                vis[nx][ny][1] = vis[x][y][0] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    cout << bfs();
}