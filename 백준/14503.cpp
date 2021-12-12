#include <bits/stdc++.h>
using namespace std;

int board[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;
int rx, ry, rd;
int cnt = 0;

void func(int x, int y, int d)
{
    board[x][y] = 2;
    cnt++;
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        d--;
        if (d < 0)
            d += 4;
        nx = x + dx[d];
        ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (board[nx][ny] == 0)
        {
            func(nx, ny, d);
            return;
        }
    }
    nx = x + dx[(d + 2) % 4];
    ny = y + dy[(d + 2) % 4];
    if (board[nx][ny] == 2)
    {
        cnt--;
        func(nx, ny, d);
        return;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> rx >> ry >> rd;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    func(rx, ry, rd);

    cout << cnt;
}