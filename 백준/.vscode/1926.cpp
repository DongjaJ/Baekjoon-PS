#include <bits/stdc++.h>
using namespace std;
int board[505][505];
int visited[505][505];
int group[300000];

#define x first
#define y second

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

int bfs(int a, int b)
{
    queue<pair<int, int>> q;
    visited[a][b] = 1;
    q.push(make_pair(a, b));
    int sum = 0;
    while (!q.empty())
    {
        pair<int, int> tmp = q.front();
        q.pop();
        sum++;
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny] || !board[nx][ny])
                continue;
            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] && !visited[i][j])
            {
                group[cnt++] = bfs(i, j);
            }
        }
    }

    int m = 0;
    cout << cnt << "\n";
    for (int i = 0; i < cnt; i++)
    {
        if (group[i] > m)
            m = group[i];
    }
    cout << m;
}