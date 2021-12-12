#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string board[1000];
int d[1000][1000];
int d2[1000][1000];
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
            if (board[nx][ny] == '#' || d[nx][ny] >= 0)
                continue;
            d[nx][ny] = d[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return;
}

void bfs2()
{
    while (!q2.empty())
    {
        int x = q2.front().first;
        int y = q2.front().second;
        q2.pop();
        //cout << x << ' ' << y << '\n';
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            {
                cout << d2[x][y] + 1 << '\n';
                return;
            }
            if (board[nx][ny] == '#' || d2[nx][ny] >= 0)
                continue;
            if (d[nx][ny] != -1 && d[nx][ny] <= d2[x][y] + 1)
                continue;
            d2[nx][ny] = d2[x][y] + 1;
            q2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    while (k--)
    {
        cin >> m >> n;

        while (!q.empty())
            q.pop();
        while (!q2.empty())
            q2.pop();

        for (int i = 0; i < n; i++)
        {
            cin >> board[i];
            fill(d[i], d[i] + m, -1);
            fill(d2[i], d2[i] + m, -1);
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '*')
                {
                    q.push({i, j});
                    d[i][j] = 0;
                }
                if (board[i][j] == '@')
                {
                    q2.push({i, j});
                    d2[i][j] = 0;
                }
            }
        }

        bfs();

        bfs2();
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << d2[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}