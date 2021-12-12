#include <bits/stdc++.h>
using namespace std;

// n,e,s,w
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int a, b, n, m;

int board[101][101];

vector<tuple<int, int, int>> rob = {{0, 0, 0}};
vector<tuple<int, char, int>> mv;

bool OOB(int x, int y)
{
    if (x <= 0 || y <= 0 || x > a || y > b)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int x, y, d;
        char dir;
        cin >> x >> y >> dir;
        if (dir == 'N')
            d = 0;
        else if (dir == 'E')
            d = 1;
        else if (dir == 'S')
            d = 2;
        else
            d = 3;
        rob.push_back({x, y, d});
        board[x][y] = i;
    }

    int idx, r;
    char cmd;

    while (m--)
    {
        cin >> idx >> cmd >> r;

        mv.push_back({idx, cmd, r});
    }

    for (auto it : mv)
    {
        tie(idx, cmd, r) = it;

        int x, y, d;
        tie(x, y, d) = rob[idx];

        // LR complete yet
        if (cmd == 'L')
        {
            d -= r;
            while (d < 0)
                d += 4;
            rob[idx] = {x, y, d};
        }

        else if (cmd == 'R')
        {
            d += r;
            d %= 4;
            rob[idx] = {x, y, d};
        }

        else
        {
            int nx = x, ny = y;
            while (r--)
            {
                nx += dx[d];
                ny += dy[d];
                // cout << nx << ' ' << ny << '\n';
                if (OOB(nx, ny))
                {
                    cout << "Robot " << idx << " crashes into the wall\n";
                    return 0;
                }
                if (board[nx][ny] != 0)
                {
                    cout << "Robot " << idx << " crashes into robot " << board[nx][ny] << "\n";
                    return 0;
                }
            }
            board[x][y] = 0;
            board[nx][ny] = idx;
            rob[idx] = {nx, ny, d};
        }
    }
    cout << "OK";
}