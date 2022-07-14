#include <bits/stdc++.h>
using namespace std;

int board[505][505];
int d[505][505];
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> board[i][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + board[i][j];
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; i++)
	{
		ans = max(d[n][i], ans);
	}
	cout << ans;
}
