#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int board[20][20];
int fre[401][4];
int n;
vector<vector<int>> v;

bool OOB(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return true;
    return false;
}

int calscore(int s)
{
    if (s == 0)
        return 0;
    if (s == 1)
        return 1;

    int res = 1;
    while (--s)
    {
        res *= 10;
    }
    return res;
}

// continue
int cnt0(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (OOB(nx, ny))
            continue;
        cnt += (board[nx][ny] == 0);
    }
    return cnt;
}

int cntfriend(int x, int y, int idx)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (OOB(nx, ny))
            continue;
        for (int j = 1; j < 5; j++)
        {
            cnt += (board[nx][ny] == v[idx][j]);
        }
    }
    return cnt;
}

int sumfriend(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (OOB(nx, ny))
            continue;
        for (int j = 0; j < 4; j++)
        {
            cnt += (board[nx][ny] == fre[board[x][y]][j]);
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n * n; i++)
    {
        vector<int> v1;
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
        for (int j = 0; j < 4; j++)
        {
            cin >> fre[tmp][j];
            v1.push_back(fre[tmp][j]);
        }
        v.push_back(v1);
    }

    for (int i = 0; i < n * n; i++)
    {
        int nowx = 0, nowy = 0, mx0 = -1, mxfre = -1;
        // cout << v[i][0] << '\n';
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (board[j][k] != 0)
                    continue;

                int nowfre = cntfriend(j, k, i);
                int now0 = cnt0(j, k);
                // cout << mxfre << ' ' << mx0 << ' ' << j << ' ' << k << ' ' << nowfre << ' ' << now0 << " " << nowx << ' ' << nowy << '\n';
                if (nowfre > mxfre)
                {
                    nowx = j;
                    nowy = k;
                    mxfre = nowfre;
                    mx0 = now0;
                    continue;
                }

                if (nowfre == mxfre && now0 > mx0)
                {
                    nowx = j;
                    nowy = k;
                    mxfre = nowfre;
                    mx0 = now0;
                    continue;
                }
            }
        }

        board[nowx][nowy] = v[i][0];
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res += calscore(sumfriend(i, j));
        }
    }

    cout << res;

    // cout << "\n\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}