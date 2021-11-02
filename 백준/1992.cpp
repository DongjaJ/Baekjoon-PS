#include <bits/stdc++.h>
using namespace std;

int k;
int board[70][70];

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

void func(int x, int y, int n)
{
    if (check(x, y, n))
    {
        cout << board[x][y];
        return;
    }
    cout << "(";
    int tmp = n / 2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            func(x + i * tmp, y + j * tmp, tmp);
        }
    }
    cout << ")";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < k; j++)
        {
            board[i][j] = s[j] - '0';
        }
    }

    func(0, 0, k);
}