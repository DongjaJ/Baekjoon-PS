#include <bits/stdc++.h>
using namespace std;

int m, n, h;
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};

int board[100][100][100];

queue<pair<int, pair<int, int>>> q;

int main()
{
    ios::sync_with_stdio(0);

    cin >> m >> n >> h;

    int ch = true;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                    q.push({i, {j, k}});
                //tomato
                if (board[i][j][k] == 0)
                    ch = false;
            }
        }
    }

    if (ch)
    {
        cout << '0' << '\n';
        return 0;
    }

    while (!q.empty())
    {
        int z = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        //cout << z << ' ' << x << ' ' << y << '\n';
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h)
                continue;
            if (board[nz][nx][ny] == -1 || board[nz][nx][ny] > 0)
                continue;
            board[nz][nx][ny] = board[z][x][y] + 1;
            q.push({nz, {nx, ny}});
        }
    }

    //cout << "\n\n";
    int mx = 0;
    for (int i = 0; i < h; i++)
    {
        if (mx == -1)
            break;
        for (int j = 0; j < n; j++)
        {
            if (mx == -1)
                break;
            for (int k = 0; k < m; k++)
            {
                if (board[i][j][k] == 0)
                {
                    mx = -1;
                    break;
                }
                mx = max(mx, board[i][j][k]);
                //cout << board[i][j][k] << ' ';
            }
            //cout << '\n';
        }
        //cout << '\n';
    }

    if (mx != -1)
        mx -= 1;
    cout << mx;
}