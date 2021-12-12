#include <bits/stdc++.h>
using namespace std;

char board[10][10];
char board1[10][10];
char board2[10][10];

int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[8] = {-1, 1, 0, 1, -1, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board1[i][j];

    bool check = false;
    for (int i = 0; i < n; i++)
    {
        if (check)
            break;
        for (int j = 0; j < n; j++)
        {
            if (board1[i][j] == 'x' && board[i][j] == '*')
            {
                check = true;
                break;
            }
        }
        cout << '\n';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board1[i][j] == 'x')
            {
                int cnt = 0;
                for (int k = 0; k < 8; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if (board[nx][ny] == '*')
                        cnt++;
                }
                board2[i][j] = cnt + '0';
            }
            else
                board2[i][j] = '.';
        }
    }

    cout << check << '\n';
    if (check)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '*')
                    cout << '*';
                else
                    cout << board2[i][j];
            }
            cout << '\n';
        }
    }
    //지ㅣ밟음
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board2[i][j];
            cout << '\n';
        }
    }
}