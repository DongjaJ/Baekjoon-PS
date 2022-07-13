#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f

int d[20001];
priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<pair<int, int>> edge[20001];
int v, e, s;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> s;
	while (e--)
	{
		int st, en, cost;
		cin >> st >> en >> cost;
		edge[st].push_back({cost, en});
	}

	fill(d, d + v + 1, INF);
	d[s] = 0;
	pq.push({0, s});
	while (pq.size())
	{
		auto cur = pq.top();
		pq.pop();
		if (d[cur.second] != cur.first)
			continue;
		for (auto i : edge[cur.second])
		{
			if (d[i.second] <= d[cur.second] + i.first)
				continue;
			d[i.second] = d[cur.second] + i.first;
			pq.push({d[i.second], i.second});
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}
}
