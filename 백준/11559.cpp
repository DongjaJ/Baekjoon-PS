#include <bits/stdc++.h>
using namespace std;

string board[12];
int vis[12][6];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void down()
{
    //char a[12] = {'.', '.', '.', '.', '.', '.', '.', '.', '.', 'c', '1', '2'};

    for (int j = 0; j < 6; j++)
    {
        string tmp = "............";
        int idx = 11;
        for (int i = 11; i >= 0; i--)
        {
            if (board[i][j] == '.')
                continue;
            if (tmp[idx] == '.')
                tmp[idx--] = board[i][j];
        }
        for (int i = 0; i < 12; i++)
        {
            board[i][j] = tmp[i];
        }
    }
}
//size 4 ?
int bfs(int x, int y)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
                continue;
            if (board[nx][ny] != board[x][y] || vis[nx][ny])
                continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    return cnt;
}

//board change
void bfs2(int x, int y)
{
    queue<pair<int, int>> q;
    int tmp = board[x][y];
    board[x][y] = '.';
    q.push({x, y});
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        //cout << xx << ' ' << yy << '\n';
        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
                continue;
            if (board[nx][ny] != tmp)
                continue;
            board[nx][ny] = '.';
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 6; j++)
            cin >> board[i][j];

    down();

    int cnt = 0;
    while (1)
    {

        for (int i = 0; i < 12; i++)
            fill(vis[i], vis[i] + 6, 0);

        down();
        bool ch = true;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (board[i][j] != '.' && !vis[i][j])
                {
                    if (bfs(i, j) >= 4)
                    {
                        bfs2(i, j);
                        ch = false;
                    }
                }
            }
        }

        // for (int i = 0; i < 12; i++)
        // {
        //     for (int j = 0; j < 6; j++)
        //     {
        //         cout << board[i][j];
        //     }
        //     cout << '\n';
        // }

        // break x
        if (ch)
        {
            cout << cnt << '\n';
            return 0;
        }
        cnt++;
    }
}