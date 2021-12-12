#include <bits/stdc++.h>
using namespace std;

int vis[300][300];
int board[300][300];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<int, int>> q;

int n, m;

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
            if (board[nx][ny] == 0 || vis[nx][ny] != 0)
                continue;
            vis[nx][ny] = vis[x][y];
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int year = 0;
    while (1)
    {
        int cnt = 0;

        for (int i = 0; i < n; i++)
            fill(vis[i], vis[i] + m, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] != 0 && vis[i][j] == 0)
                {
                    vis[i][j] = ++cnt;
                    q.push({i, j});
                    bfs();
                }
            }
        }
        //cout << cnt << '\n';
        if (cnt >= 2)
        {
            cout << year << '\n';
            break;
        }
        if (cnt == 0)
        {
            cout << '0' << '\n';

            // for (int i = 0; i < n; i++)
            // {
            //     for (int j = 0; j < m; j++)
            //     {
            //         cout << board[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }

            break;
        }

        int tmp[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] != 0)
                {
                    int mcnt = 0;
                    for (int d = 0; d < 4; d++)
                    {
                        int x = i + dx[d];
                        int y = j + dy[d];
                        if (x < 0 || y < 0 || x >= n || y >= m)
                            continue;
                        mcnt += (board[x][y] == 0);
                    }
                    tmp[i][j] = max(0, board[i][j] - mcnt);
                    continue;
                }
                tmp[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board[i][j] = tmp[i][j];

        year++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}