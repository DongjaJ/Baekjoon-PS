#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;

int board[101][101];
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
			board[i][j] = i == j ? 0 : INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (board[a][b] > c)
			board[a][b] = c;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (board[j][i] < board[j][k] - board[i][k])
					board[j][k] = board[j][i] + board[i][k];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}
