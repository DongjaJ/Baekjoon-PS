#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int n, m;

char board[55][55];
int vis[55][55];

int flag = 0;

int mx = -1;

bool OOB(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return true;
	return false;
}

int dfs(int x, int y)
{
	if (OOB(x, y) || board[x][y] == 'H')
		return 0;

	if (vis[x][y] == -1)
	{
		vis[x][y] = 0;
		int cur = -1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i] * (board[x][y] - '0');
			int ny = y + dy[i] * (board[x][y] - '0');
			cur = max(cur, dfs(nx, ny) + 1);
		}
		vis[x][y] = cur;
	}
	else if (vis[x][y] == 0)
	{
		flag = 1;
		return 0;
	}
	return vis[x][y];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++)
		fill(vis[i], vis[i] + m, -1);

	dfs(0, 0);
	// cout << "flag : " << flag << '\n';
	if (flag == 1)
	{
		cout << -1;
		return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mx = max(mx, vis[i][j]);

	cout << mx;
}
