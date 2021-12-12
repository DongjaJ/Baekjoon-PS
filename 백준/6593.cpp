#include <bits/stdc++.h>
using namespace std;

int l, r, c;

char board[30][30][30];
int d[30][30][30];
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};

queue<tuple<int, int, int>> q;

int bfs()
{
    while (q.size())
    {
        int x, y, z;
        tie(z, x, y) = q.front();
        q.pop();

        if (board[z][x][y] == 'E')
        {
            return d[z][x][y];
        }

        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx < 0 || ny < 0 || nz < 0 || nz >= l || nx >= r || ny >= c)
                continue;
            if (d[nz][nx][ny] != -1 || board[nz][nx][ny] == '#')
                continue;
            d[nz][nx][ny] = d[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> l >> r >> c;

        if (l == 0 && r == 0 && c == 0)
            break;

        while (q.size())
            q.pop();
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    cin >> board[i][j][k];
                    d[i][j][k] = -1;
                    if (board[i][j][k] == 'S')
                    {
                        q.push({i, j, k});
                        d[i][j][k] = 0;
                    }
                }
            }
        }

        int res = bfs();
        if (res == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << res << " minute(s).\n";
    }
}