#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];
char board[1005][1005];
int n, m;

int mx = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] == '1')
			{
				int mn = min(d[i - 1][j], d[i][j - 1]);
				mn = min(mn, d[i - 1][j - 1]);
				d[i][j] = mn + 1;
				mx = max(mx, d[i][j]);
			}
		}
	}

	cout << mx * mx;
}
