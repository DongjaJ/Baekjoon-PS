#include <bits/stdc++.h>
using namespace std;

int board[201];
int board2[201];
int rob[201];
int rob2[201];

int n, k;

// x
vector<int> robot;

int cnt()
{
    int sum = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        sum += (board[i] == 0);
    }
    return sum;
}

int er(int num)
{
    int er_idx = -1;
    for (int i = 0; i < robot.size(); i++)
    {
        if (robot[i] == num)
        {
            er_idx = i;
            break;
        }
    }
    return er_idx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= 2 * n; i++)
        cin >> board[i];

    int stage = 0, robot_idx = 0;
    while (1)
    {
        stage++;

        // 1
        for (int i = 1; i <= 2 * n; i++)
        {
            board2[i] = board[i];
            rob2[i] = rob[i];
        }

        for (int i = 1; i <= 2 * n; i++)
        {
            int next_i;
            if (i == 2 * n)
                next_i = 1;
            else
                next_i = i + 1;
            board[next_i] = board2[i];
            rob[next_i] = rob2[i];
        }

        // for (int i = 1; i <= 2 * n; i++)
        // {
        //     cout << i << ' ';
        //     cout << board[i] << ' ' << rob[i] << '\n';
        // }

        for (auto &i : robot)
            i++;

        int er_idx = er(n);
        if (er_idx != -1)
        {
            robot.erase(robot.begin() + er_idx);
            rob[n] = 0;
        }

        // 2
        for (auto &i : robot)
        {
            int next_id;
            if (i == 2 * n)
                next_id = 1;
            else
                next_id = i + 1;
            if (board[next_id] > 0 && rob[next_id] == 0)
            {
                board[next_id]--;
                rob[next_id] = 1;
                rob[i] = 0;
                i = next_id;
            }
        }

        er_idx = er(n);
        if (er_idx != -1)
        {
            robot.erase(robot.begin() + er_idx);
            rob[n] = 0;
        }

        // 3
        if (rob[1] == 0 && board[1] > 0)
        {
            robot.push_back(1);
            rob[1] = 1;
            board[1]--;
        }

        // for (auto &i : robot)
        // {
        //     cout << i << ' ';
        // }
        // cout << '\n';

        // 4
        if (cnt() >= k)
            break;
    }

    cout << stage << '\n';
}