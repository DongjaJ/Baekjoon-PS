#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int a[2][7];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    while (n--)
    {
        int x, y;
        cin >> x >> y;

        a[x][y]++;
        if (a[x][y] == m)
        {
            cnt++;
            a[x][y] = 0;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            cnt += (a[i][j] != 0);
        }
    }

    cout << cnt;
}