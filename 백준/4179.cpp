#include <bits/stdc++.h>
using namespace std;

string board[1000];
int vis[1000][1000];
int vis2[1000][1000];
int m, n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<int, int>> q;
queue<pair<int, int>> q2;

void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (board[nx][ny] == '#' || vis[nx][ny] != -1)
                continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

void bfs2()
{
    while (!q2.empty())
    {
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                cout << vis2[x][y] + 1;
                return;
            }
            if (board[nx][ny] == '#' || vis2[nx][ny] != -1)
                continue;
            if (vis[nx][ny] != -1 && vis[nx][ny] <= vis2[x][y] + 1)
                continue;
            vis2[nx][ny] = vis2[x][y] + 1;
            q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        fill(vis[i], vis[i] + m, -1);
        fill(vis2[i], vis2[i] + m, -1);
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'F')
            {
                vis[i][j] = 0;
                q.push({i, j});
            }
            if (board[i][j] == 'J')
            {
                vis2[i][j] = 0;
                q2.push({i, j});
            }
        }
    }

    bfs();

    bfs2();
}