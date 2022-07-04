#include <bits/stdc++.h>

using namespace std;

int check[3][15][15];
int board[10][10];

vector<pair<int, int>> v;

int flag;

void func(int n)
{
	if (flag)
		return;
	if (n == v.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		flag++;
		return;
	}

	int x = v[n].first;
	int y = v[n].second;

	// cout << x << ' ' << y << ' ' << x / 3 * 3 + y / 3 << '\n';

	for (int i = 1; i <= 9; i++)
	{
		if (check[0][x][i] || check[1][y][i] || check[2][x / 3 * 3 + y / 3][i])
			continue;
		board[x][y] = i;
		check[0][x][i] = 1;
		check[1][y][i] = 1;
		check[2][x / 3 * 3 + y / 3][i] = 1;
		// cout << i << '\n';
		func(n + 1);
		check[0][x][i] = 0;
		check[1][y][i] = 0;
		check[2][x / 3 * 3 + y / 3][i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				v.push_back({i, j});
			}
			else
			{
				check[0][i][board[i][j]] = 1;
				check[1][j][board[i][j]] = 1;
				check[2][i / 3 * 3 + j / 3][board[i][j]] = 1;
			}
		}
	}
	func(0);
}
