#include <bits/stdc++.h>
using namespace std;

string n;
int k;

int mx = -1;

set<pair<string, int>> s;

void bfs()
{
	queue<pair<string, int>> q;
	q.push({n, 0});
	while (q.size())
	{
		string x;
		int t;
		tie(x, t) = q.front();
		q.pop();
		if (t == k)
		{
			mx = max(mx, stoi(x));
			continue;
		}
		for (int i = 0; i < x.size(); i++)
		{
			for (int j = i + 1; j < x.size(); j++)
			{
				string tmp = x.substr(0, i) + x[j] + x.substr(i + 1, j - i - 1) + x[i] + x.substr(j + 1, x.size() - j);
				if (tmp[0] == '0')
					continue;
				if (s.count({tmp, t + 1}))
					continue;
				s.insert({tmp, t + 1});
				q.push({tmp, t + 1});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	bfs();

	if (mx == -1)
		cout << -1;
	else
		cout << mx;
}
