#include <bits/stdc++.h>
using namespace std;

int board[2500][2500];
int cnt[3];
bool check(int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (board[x][y] != board[i][j])
                return false;
        }
    }
    return true;
}

void solve(int x, int y, int n)
{
    if (check(x, y, n))
    {
        cnt[board[x][y] + 1]++;
        return;
    }
    int tmp = n / 3;
    for (int i = x; i < x + n; i += tmp)
        for (int j = y; j < y + n; j += tmp)
            solve(i, j, tmp);
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            cin >> board[i][j];
    solve(0, 0, k);
    for (auto i : cnt)
        cout << i << '\n';
}
