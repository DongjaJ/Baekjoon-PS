#include <bits/stdc++.h>
using namespace std;

int n, m, K;

int board[200][200];
int vis[200][200][31];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int hx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    for (int i = 0; i <= K; i++)
        vis[0][0][i] = 0;
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
            if (board[nx][ny] == 1 || vis[nx][ny][b] != -1)
                continue;
            vis[nx][ny][b] = vis[x][y][b] + 1;
            q.push({nx, ny, b});
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = x + hx[i];
            int ny = y + hy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (board[nx][ny] == 1 || vis[nx][ny][b + 1] != -1)
                continue;
            if (b == K)
                continue;
            //cout << nx << ' ' << ny << ' ' << b + 1 << '\n';
            vis[nx][ny][b + 1] = vis[x][y][b] + 1;
            q.push({nx, ny, b + 1});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;

    cin >> m >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k <= K; k++)
                vis[i][j][k] = -1;

    cout << bfs();

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //     {
    //         cout << vis[i][j][2] << ' ';
    //     }
    //     cout << '\n';
    // }
}