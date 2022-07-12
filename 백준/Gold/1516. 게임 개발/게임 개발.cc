#include <bits/stdc++.h>

using namespace std;

int n, m, tmp;

int deg[505];
vector<int> adj[505];
int t[505];
int ans[505];

queue<int> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i];
		while (cin >> tmp)
		{
			if (tmp == -1)
				break;
			adj[tmp].push_back(i);
			deg[i]++;
		}
		ans[i] += t[i];
	}

	for (int i = 1; i <= n; i++)
		if (deg[i] == 0)
			q.push(i);

	while (q.size())
	{
		int x = q.front();
		q.pop();
		for (auto i : adj[x])
		{
			deg[i]--;
			if (deg[i] == 0)
				q.push(i);
			ans[i] = max(ans[i], t[i] + ans[x]);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
}
