#include <bits/stdc++.h>
using namespace std;

int board[8][8];
int board2[8][8];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;

vector<pair<int, int>> v;
vector<pair<int, int>> b;

int mx = 0;

void bfs()
{
    queue<pair<int, int>> q;
    for (auto &i : b)
        q.push({i.first, i.second});

    while (q.size())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (board2[nx][ny] != 0)
                continue;
            board2[nx][ny] = board2[x][y];
            q.push({nx, ny});
        }
    }
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
            if (board[i][j] == 0)
                v.push_back({i, j});
            if (board[i][j] == 2)
                b.push_back({i, j});
        }
    }

    vector<int> brute(v.size(), 1);
    fill(brute.begin(), brute.begin() + 3, 0);

    do
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                board2[i][j] = board[i][j];

        int cnt = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (cnt == 3)
                break;
            if (brute[i] == 0)
            {
                int x = v[i].first;
                int y = v[i].second;
                board2[x][y] = 1;
                cnt++;
            }
        }

        bfs();

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board2[i][j] == 0)
                    res++;
            }
        }
        mx = max(mx, res);
    } while (next_permutation(brute.begin(), brute.end()));

    cout << mx;
}