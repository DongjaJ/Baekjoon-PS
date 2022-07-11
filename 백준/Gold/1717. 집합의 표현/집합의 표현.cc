#include <bits/stdc++.h>

using namespace std;

int p[1000005];

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

int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		p[i] = i;

	while (m--)
	{
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0)
		{
			join(a, b);
		}
		else
		{
			if (find(a) == find(b))
			{
				cout << "YES\n";
			}
			else
				cout << "NO\n";
		}
	}
}
