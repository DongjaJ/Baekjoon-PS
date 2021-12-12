#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

char board[10][10];
int vis[10][10];
int check[10][10];
int pick[30];
int answer = 0;

//연결 체크
bool bfs()
{
    int cnt = 1;
    queue<pair<int, int>> q;

    for (int i = 0; i < 5; i++)
    {
        fill(vis[i], vis[i] + 5, 0);
        fill(check[i], check[i] + 5, 0);
    }

    int first = 1;
    for (int i = 0; i < 25; i++)
    {
        if (pick[i])
        {
            if (first)
            {
                q.push({i / 5, i % 5});
                vis[i / 5][i % 5] = 1;
                first = 0;
            }
            check[i / 5][i % 5] = 1;
        }
    }

    while (!q.empty())
    {
        if (cnt == 7)
            return true;

        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;
            if (vis[nx][ny] || !check[nx][ny])
                continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
            cnt++;
        }
    }

    return false;
}

//다솜파
bool checkd()
{
    int cnt = 0;
    for (int i = 0; i < 25; i++)
    {
        if (pick[i] && board[i / 5][i % 5] == 'S')
            cnt++;
    }

    if (cnt >= 4)
        return true;
    else
        return false;
}

void btr(int n, int s)
{
    if (n == 7)
    {
        //다솜 우열, 가로 세로 체크
        if (checkd() && bfs())
            answer++;
        return;
    }

    for (int i = s; i < 25; i++)
    {
        if (pick[i])
            continue;
        pick[i] = 1;
        btr(n + 1, i);
        pick[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    btr(0, 0);
    cout << answer;
}