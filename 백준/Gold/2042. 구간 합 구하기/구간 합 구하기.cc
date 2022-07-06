#include <bits/stdc++.h>

using namespace std;

long long arr[1000005];
vector<long long> tree;

int n, m, k;

int treesize, stidx;

long long func(int idx, int st, int en, int treest, int treeen)
{
	if (en < treest || st > treeen)
		return 0;
	if (st >= treest && en <= treeen)
		return tree[idx];
	int mid = (st + en) / 2;
	return func(idx * 2, st, mid, treest, treeen) + func(idx * 2 + 1, mid + 1, en, treest, treeen);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int d = 1;
	while ((1 << d) < n)
	{
		d++;
	}
	treesize = (1 << (d + 1)) - 1;
	stidx = 1 << d;
	tree.resize(treesize);
	for (int i = 0; i < n; i++)
	{
		int idx = stidx + i;
		tree[idx] = arr[i];
		idx /= 2;
		while (idx > 0)
		{
			tree[idx] += arr[i];
			idx /= 2;
		}
	}

	for (int i = 0; i < m + k; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			int idx = stidx + b - 1;
			long long dif = c - tree[idx];
			tree[idx] = c;
			idx /= 2;
			while (idx > 0)
			{
				tree[idx] += dif;
				idx /= 2;
			}
		}
		else
		{
			long long ans = func(1, 1, stidx, b, c);
			cout << ans << '\n';
		}
	}
}
