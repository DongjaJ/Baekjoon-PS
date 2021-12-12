#include <bits/stdc++.h>
using namespace std;

int N, K, L, sec;
int board[101][101];
queue<pair<int, char>> snake;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> tail;

void func(int x, int y, int d)
{
    //벽일때
    if (x < 0 || y < 0 || x >= N || y >= N)
        return;
    //몸 만날떄
    if (board[x][y] == 2)
        return;

    //사과 있거나 없을떄
    if (board[x][y] == 0)
    {
        int tx = tail.front().first;
        int ty = tail.front().second;
        board[tx][ty] = 0;
        tail.pop();
    }
    board[x][y] = 2;
    tail.push({x, y});

    sec++;

    //뱀 방향 변할때
    if (!snake.empty())
    {
        if (sec == snake.front().first)
        {
            if (snake.front().second == 'L')
                d++;
            else
                d--;
            snake.pop();
        }
    }
    if (d < 0)
        d += 4;
    else if (d >= 4)
        d -= 4;
    int nx = x + dx[d];
    int ny = y + dy[d];

    func(nx, ny, d);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }
    cin >> L;
    while (L--)
    {
        int x;
        char y;
        cin >> x >> y;
        snake.push({x, y});
    }

    tail.push({0, 0});
    func(0, 1, 0);
    sec++;

    cout << sec;
}