#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
using namespace std;

int n, m;
long long d[505];
vector<tuple<int, int, int>> edge;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	fill(d, d + n + 1, INF);
	edge.resize(m);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = {a, b, c};
	}

	d[1] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int st, en, cost;
			tie(st, en, cost) = edge[j];
			if (d[st] < INF)
				d[en] = min(d[en], d[st] + cost);
		}
	}

	bool iscycle = false;
	for (int j = 0; j < m; j++)
	{
		int st, en, cost;
		tie(st, en, cost) = edge[j];
		if (d[st] < INF && d[en] > d[st] + cost)
		{
			iscycle = true;
			break;
		}
	}

	if (iscycle)
		cout << "-1\n";
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (d[i] == INF)
				cout << -1 << '\n';
			else
				cout << d[i] << '\n';
		}
	}
}
