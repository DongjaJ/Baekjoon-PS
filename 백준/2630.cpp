#include <bits/stdc++.h>
using namespace std;

int board[128][128];
int n;
int cnt1 = 0;
int cnt2 = 0;

void check()
{
}

void func(int x, int y, int k)
{
    if (k == 1)
    {
        if (board[x][y])
            cnt1++;
        else
            cnt2++;
        return;
    }

    bool ch = true;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (board[x][y] != board[x + i][y + j])
            {
                ch = false;
                break;
            }
        }
    }
    if (ch)
    {
        //cout << x << ' ' << y << ' ' << k << '\n';
        if (board[x][y])
            cnt1++;
        else
            cnt2++;
        return;
    }
    int tmp = k / 2;
    func(x, y, tmp);
    func(x + tmp, y, tmp);
    func(x, y + tmp, tmp);
    func(x + tmp, y + tmp, tmp);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    func(0, 0, n);

    cout << cnt2 << '\n';
    cout << cnt1;
}