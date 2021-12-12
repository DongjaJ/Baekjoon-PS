#include <bits/stdc++.h>
using namespace std;

int board[500][500];
int n, r, c, m;
int mx = 0;

int stick[7][4][4] = {{{
                           1,
                           1,
                           1,
                           1,
                       },
                       {
                           0,
                       },
                       {
                           0,
                       },
                       {
                           0,
                       }},
                      {{
                           1,
                           1,
                       },
                       {
                           1,
                           1,
                       },
                       {
                           0,
                       },
                       {
                           0,
                       }},
                      {{
                           1,
                           0,
                       },
                       {
                           1,
                           0,
                       },
                       {
                           1,
                           1,
                       },
                       {
                           0,
                       }},
                      {{
                           1,
                           0,
                       },
                       {
                           1,
                           1,
                       },
                       {
                           0,
                           1,
                       },
                       {
                           0,
                       }},
                      {{
                           1,
                           1,
                           1,
                       },
                       {
                           0,
                           1,
                           0,
                       },
                       {
                           0,
                       },
                       {
                           0,
                       }},
                      {{
                           0,
                           1,
                       },
                       {
                           0,
                           1,
                       },
                       {
                           1,
                           1,
                       },
                       {
                           0,
                       }},
                      {{
                           0,
                           1,
                       },
                       {
                           1,
                           1,
                       },
                       {
                           1,
                           0,
                       }}};

void rotate(int ind)
{
    int tmp[4][4];

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tmp[i][j] = stick[ind][i][j];

    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            stick[ind][i][j] = tmp[r - 1 - j][i];

    swap(r, c);

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << stick[ind][i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
}

void check(int ind, int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (stick[ind][i][j] == 1)
            {
                //cout << x + i << ' ' << y + j << ' ' << board[x + i][y + j] << ' ';
                cnt += board[x + i][y + j];
            }
        }
    }
    // cout << cnt << '\n';
    mx = max(mx, cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // for (int i = 0; i < 7; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         for (int k = 0; k < 4; k++)
    //         {
    //             cout << stick[i][j][k] << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';
    // }

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    r = 1;
    c = 4;

    for (int i = 0; i <= n - r; i++)
    {
        for (int j = 0; j <= m - c; j++)
        {
            check(0, i, j);
        }
    }

    rotate(0);

    for (int i = 0; i <= n - r; i++)
    {
        for (int j = 0; j <= m - c; j++)
        {
            check(0, i, j);
        }
    }

    r = 2;
    c = 2;

    for (int i = 0; i <= n - r; i++)
    {
        for (int j = 0; j <= m - c; j++)
        {
            check(1, i, j);
        }
    }

    r = 3;
    c = 2;

    for (int t = 0; t < 4; t++)
    {
        for (int i = 0; i <= n - r; i++)
        {
            for (int j = 0; j <= m - c; j++)
            {
                check(2, i, j);
            }
        }
        rotate(2);
    }

    for (int t = 0; t < 4; t++)
    {
        for (int i = 0; i <= n - r; i++)
        {
            for (int j = 0; j <= m - c; j++)
            {
                check(3, i, j);
            }
        }
        rotate(3);
    }

    for (int t = 0; t < 4; t++)
    {
        for (int i = 0; i <= n - r; i++)
        {
            for (int j = 0; j <= m - c; j++)
            {
                check(5, i, j);
            }
        }
        rotate(5);
    }

    for (int t = 0; t < 4; t++)
    {
        for (int i = 0; i <= n - r; i++)
        {
            for (int j = 0; j <= m - c; j++)
            {
                check(6, i, j);
            }
        }
        rotate(6);
    }

    r = 2;
    c = 3;
    for (int t = 0; t < 4; t++)
    {
        for (int i = 0; i <= n - r; i++)
        {
            for (int j = 0; j <= m - c; j++)
            {
                check(4, i, j);
            }
        }
        rotate(4);
    }

    cout << mx;
}