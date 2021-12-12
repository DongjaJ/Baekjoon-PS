#include <bits/stdc++.h>
using namespace std;

//z,x,y
int board[5][5][5];
int board2[5][5][5];
int board3[5][5][5];
int vis[5][5][5];
int p[5] = {0, 1, 2, 3, 4};

int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};

int mn = 100000;

void rotate(int z)
{
    int tmp[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            tmp[i][j] = board2[z][i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            board2[z][i][j] = tmp[5 - j - 1][i];
}

void bfs()
{
    if (board3[0][0][0] == 0)
        return;
    //z,x,y
    queue<tuple<int, int, int>> q;

    vis[0][0][0] = 0;
    q.push({0, 0, 0});
    while (q.size())
    {
        int x, y, z;
        tie(z, x, y) = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5)
                continue;
            if (board3[nz][nx][ny] == 0 || vis[nz][nx][ny] != -1)
                continue;
            vis[nz][nx][ny] = vis[z][x][y] + 1;
            q.push({nz, nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> board[i][j][k];

    for (int brute = 0; brute < (1 << 10); brute++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    board2[i][j][k] = board[i][j][k];
                    vis[i][j][k] = -1;
                }
            }
        }

        int tmp = brute;

        for (int d = 0; d < 5; d++)
        {
            int dir = tmp % 4;
            tmp /= 4;
            while (dir--)
                rotate(d);
        }

        do
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        board3[i][j][k] = board2[p[i]][j][k];
                        vis[i][j][k] = -1;
                    }
                }
            }

            bfs();
            if (vis[4][4][4] == -1)
                continue;
            mn = min(mn, vis[4][4][4]);

        } while (next_permutation(p, p + 5));
    }
    if (mn == 100000)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << mn << '\n';
}