#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int>> adj[1005];
priority_queue<int> vis[1005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({c, b});
	}

	vis[1].push(0);
	pq.push({0, 1});
	while (pq.size())
	{
		auto cur = pq.top();
		pq.pop();
		for (auto next : adj[cur.second])
		{
			int ncost = cur.first + next.first;
			if (vis[next.second].size() == k && vis[next.second].top() > ncost)
				vis[next.second].pop();
			if (vis[next.second].size() < k)
			{
				vis[next.second].push(ncost);
				pq.push({ncost, next.second});
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[i].size() < k)
			cout << "-1\n";
		else
			cout << vis[i].top() << '\n';
	}
}
