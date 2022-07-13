#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> adj[100005];
int dep[100005];
queue<int> q;
int p[20][100005];

int LCA(int a, int b)
{
	if (dep[a] < dep[b])
	{
		int tmp = b;
		b = a;
		a = tmp;
	}
	int diff = dep[a] - dep[b];
	for (int i = 0; diff > 0; i++)
	{
		if (diff & 1)
			a = p[i][a];
		diff >>= 1;
	}

	while (a != b)
	{
		int r;
		for (r = 0; r < 18; r++)
		{
			if (p[r][a] == p[r][b])
				break;
		}
		if (r > 0)
			r--;
		a = p[r][a], b = p[r][b];
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		adj[st].push_back(en);
		adj[en].push_back(st);
	}

	for (int i = 1; i <= n; i++)
		dep[i] = -1;

	dep[1] = 0;
	q.push(1);
	while (q.size())
	{
		int now = q.front();
		q.pop();
		for (auto next : adj[now])
		{
			if (dep[next] != -1)
				continue;
			dep[next] = dep[now] + 1;
			q.push(next);
			p[0][next] = now;
		}
	}

	for (int i = 1; i < 18; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			p[i][j] = p[i - 1][p[i - 1][j]];
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
}
