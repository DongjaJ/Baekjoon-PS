#include <bits/stdc++.h>
using namespace std;

int board[1000][1000];
int vis[1000][1000][11];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, m, k;

bool OOB(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return true;
    return false;
}

int bfs()
{
    queue<tuple<int, int, int>> q;
    vis[0][0][0] = 1;
    q.push({0, 0, 0});

    while (q.size())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        // cout << x << ' ' << y << ' ' << z << '\n';
        q.pop();

        if (x == n - 1 && y == m - 1)
        {
            return vis[x][y][z];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (OOB(nx, ny))
                continue;
            if (board[nx][ny] == 0 && vis[nx][ny][z] == 0)
            {
                vis[nx][ny][z] = vis[x][y][z] + 1;
                q.push({nx, ny, z});
            }

            if (board[nx][ny] == 1 && z != k && vis[nx][ny][z + 1] == 0)
            {
                vis[nx][ny][z + 1] = vis[x][y][z] + 1;
                q.push({nx, ny, z + 1});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = s[j] - '0';
        }
    }

    cout << bfs();
}