#include <bits/stdc++.h>
using namespace std;

long long board[1025][1025];
long long d[1025][1025];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
            d[i][j] = d[i - 1][j] + d[i][j - 1] + board[i][j] - d[i - 1][j - 1];
            //cout << d[i][j] << ' ';
        }
        //cout << '\n';
    }

    while (m--)
    {
        int x1, x2, y1, y2;

        cin >> x1 >> y1 >> x2 >> y2;
        int ans;

        ans = d[x2][y2] - d[x2][y1 - 1] - d[x1 - 1][y2] + d[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
}