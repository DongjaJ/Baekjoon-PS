#include <bits/stdc++.h>
using namespace std;

bool ladd[31][11];
int n, m, h;

int mn = 999;

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        for (int j = 1; j <= h; j++)
        {
            if (ladd[j][tmp])
                tmp++;
            else if (ladd[j][tmp - 1])
                tmp--;
        }
        if (tmp != i)
            return false;
    }
    return true;
}

void func(int y, int cnt)
{
    //cout << y << ' ' << cnt << '\n';

    if (cnt > 3)
        return;

    if (check())
    {
        mn = min(cnt, mn);
        return;
    }

    for (int i = y; i <= h; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (ladd[i][j - 1])
                continue;
            if (ladd[i][j])
                continue;
            if (ladd[i][j + 1])
                continue;
            ladd[i][j] = true;
            func(i, cnt + 1);
            ladd[i][j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> h;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        ladd[x][y] = true;
    }

    func(1, 0);
    if (mn == 999)
        mn = -1;
    cout << mn << '\n';
}