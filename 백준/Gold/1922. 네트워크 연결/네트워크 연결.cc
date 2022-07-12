#include <bits/stdc++.h>

using namespace std;

int n, m, cnt, ans;

int p[1005];
vector<tuple<int, int, int>> v;
queue<tuple<int, int, int>> q;

int find(int a)
{
	if (p[a] == a)
		return a;
	return p[a] = find(p[a]);
}

void join(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	p[b] = a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({c, a, b});
	}

	for (int i = 1; i <= n; i++)
		p[i] = i;

	sort(v.begin(), v.end());

	for (auto i : v)
		q.push(i);

	while (cnt < n - 1)
	{
		int st, en, d;
		tie(d, st, en) = q.front();
		q.pop();
		if (find(st) == find(en))
			continue;
		join(st, en);
		cnt++;
		ans += d;
	}
	cout << ans;
}
