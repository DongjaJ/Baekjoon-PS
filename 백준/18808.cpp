#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c;

int note[42][42];
int paper[12][12];

bool check(int x, int y)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (note[i + x][j + y] == 1 && paper[i][j] == 1)
                return false;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (paper[i][j] == 1)
            {
                note[i + x][j + y] = 1;
            }
        }
    }

    return true;
}

void rotate()
{
    int paper2[12][12];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            paper2[i][j] = paper[i][j];
        }
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            paper[i][j] = paper2[r - 1 - j][i];
        }
    }

    swap(r, c);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while (k--)
    {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> paper[i][j];

        //rotate
        for (int t = 0; t < 4; t++)
        {
            bool ch = false;
            for (int i = 0; i <= n - r; i++)
            {
                if (ch)
                    break;
                for (int j = 0; j <= m - c; j++)
                {
                    if (check(i, j))
                    {
                        ch = true;
                        break;
                    }
                }
            }
            if (ch)
                break;
            rotate();
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cnt += note[i][j];
        }
    }

    cout << cnt;
}