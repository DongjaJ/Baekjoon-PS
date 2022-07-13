#include <bits/stdc++.h>
using namespace std;

int V, E;

vector<int> adj[10005];
int vis[10005];
int cutVertex[10005];
vector<int> ans;

int order = 0;
int dfs(int cur, int par)
{
	vis[cur] = ++order;
	int minOrder = vis[cur];
	int cnt = 0;
	for (int next : adj[cur])
	{
		if (next == par)
			continue;
		if (vis[next] > 0)
		{
			minOrder = min(minOrder, vis[next]);
		}
		else
		{
			int low = dfs(next, cur);
			if (par != 0 && low >= vis[cur])
				cutVertex[cur] = 1;
			minOrder = min(minOrder, low);
			cnt++;
		}
	}
	if (par == 0 && cnt >= 2)
		cutVertex[cur] = 1;
	return minOrder;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int st, en;
		cin >> st >> en;
		adj[st].push_back(en);
		adj[en].push_back(st);
	}

	for (int i = 1; i <= V; i++)
		if (!vis[i])
			dfs(i, 0);

	for (int i = 1; i <= V; i++)
		if (cutVertex[i])
			ans.push_back(i);

	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << ' ';
}
