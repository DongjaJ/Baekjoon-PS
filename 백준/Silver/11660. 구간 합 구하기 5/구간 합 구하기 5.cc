#include <bits/stdc++.h>
using namespace std;

int board[1025][1025];
int d[1025][1025];

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
			d[i][j] = board[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		cout << d[ex][ey] - d[sx - 1][ey] - d[ex][sy - 1] + d[sx - 1][sy - 1] << '\n';
	}
}
