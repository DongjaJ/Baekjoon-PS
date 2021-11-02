#include <bits/stdc++.h>
using namespace std;

char board[6700][6700];

void star(int x, int y, int n)
{
    if (n == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[x + i][y + j] = '*';
            }
        }
        board[x + 1][y + 1] = ' ';
        return;
    }

    int tmp = n / 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
            {
                for (int k = x + i * tmp; k < x + i * tmp + tmp; k++)
                {
                    for (int l = y + j * tmp; l < y + j * tmp + tmp; l++)
                    {
                        board[k][l] = ' ';
                    }
                }
                continue;
            }
            star(x + i * tmp, y + j * tmp, tmp);
        }
    }

    return;
}

int main()
{
    int N;
    cin >> N;
    star(0, 0, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j];
        cout << "\n";
    }
}
