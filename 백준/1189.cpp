#include <bits/stdc++.h>
using namespace std;

int r, c, k;

int cnt = 0;

vector<pair<int, int>> v;

string board[5];
int vis[5][5];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int n)
{
    if (n == k - 1)
    {
        if (v[k - 1].first == 0 && v[k - 1].second == c - 1)
            cnt++;
        // for (auto &i : v)
        //     cout << i.first << ' ' << i.second << ' ';
        //cout << '\n';
        return;
    }

    int x = v[n].first;
    int y = v[n].second;
    //cout << x << ' ' << y << '\n';
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        //cout << x << ' ' << y << '\n';
        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        if (vis[nx][ny] || board[nx][ny] == 'T')
            continue;
        vis[nx][ny] = 1;
        v.push_back({nx, ny});
        dfs(n + 1);
        v.erase(v.end() - 1);
        vis[nx][ny] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;

    for (int i = 0; i < r; i++)
        cin >> board[i];

    vis[r - 1][0] = 1;
    v.push_back({r - 1, 0});
    dfs(0);

    cout << cnt << '\n';
}