#include <bits/stdc++.h>
using namespace std;

int n;
int board[21][21];
int board2[21][21];

void rotate()
{
    int tmp[21][21];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board2[i][j] = tmp[n - 1 - j][i];
}

void func()
{

    for (int i = 0; i < n; i++)
    {
        int change[21] = {};
        int idx = 0;
        for (int j = 0; j < n; j++)
        {
            if (board2[i][j] == 0)
                continue;
            if (change[idx] == 0)
                change[idx] = board2[i][j];
            else if (change[idx] == board2[i][j])
                change[idx++] *= 2;
            else
                change[++idx] = board2[i][j];
        }

        for (int j = 0; j < n; j++)
            board2[i][j] = change[j];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int m = 0;
    for (int brute = 0; brute < 1024; brute++)
    {
        int tmp = brute;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board2[i][j] = board[i][j];

        for (int k = 0; k < 5; k++)
        {
            int d = tmp % 4;
            tmp /= 4;

            while (d--)
                rotate();

            func();
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m = max(m, board2[i][j]);
    }

    cout << m;
}