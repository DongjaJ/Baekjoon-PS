#include <bits/stdc++.h>
using namespace std;

int n, m, strx, stry, stbx, stby, mn = 100000;

char board[10][11];
char board2[10][11];
int vis[10][10][10][10];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ball
queue<tuple<int, int, int, int, int>> q;

int bfs()
{
    while (q.size())
    {
        int rx, ry, bx, by, cnt;
        tie(rx, ry, bx, by, cnt) = q.front();
        q.pop();

        if (cnt > 10)
            break;

        if (board[rx][ry] == 'O')
        {
            return cnt;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_rx = rx;
            int next_ry = ry;
            int next_bx = bx;
            int next_by = by;

            while (board[next_rx][next_ry] != '#' && board[next_rx][next_ry] != 'O')
            {
                next_rx += dx[i];
                next_ry += dy[i];
            }
            while (board[next_bx][next_by] != '#' && board[next_bx][next_by] != 'O')
            {
                next_bx += dx[i];
                next_by += dy[i];
            }

            if (board[next_bx][next_by] == 'O')
                continue;

            if (board[next_rx][next_ry] == '#')
            {
                next_rx -= dx[i];
                next_ry -= dy[i];
            }

            if (board[next_bx][next_by] == '#')
            {
                next_bx -= dx[i];
                next_by -= dy[i];
            }

            if (next_rx == next_bx && next_ry == next_by)
            {

                int disr = abs(next_rx - rx) + abs(next_ry - ry);
                int disb = abs(next_bx - bx) + abs(next_by - by);

                if (disr > disb)
                {
                    next_rx -= dx[i];
                    next_ry -= dy[i];
                }
                else
                {
                    next_bx -= dx[i];
                    next_by -= dy[i];
                }
            }

            if (vis[next_rx][next_ry][next_bx][next_by])
                continue;

            vis[next_rx][next_ry][next_bx][next_by] = 1;
            q.push({next_rx, next_ry, next_bx, next_by, cnt + 1});
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
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'B')
            {
                stbx = i;
                stby = j;
            }
            if (board[i][j] == 'R')
            {
                strx = i;
                stry = j;
            }
        }
    }

    vis[strx][stry][stbx][stby] = 1;
    q.push({strx, stry, stbx, stby, 0});

    cout << bfs() << '\n';
}
