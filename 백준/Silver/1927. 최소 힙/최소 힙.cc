#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	int n, m;
	cin >> n;
	while (n--)
	{
		cin >> m;
		if (m == 0)
		{
			if (pq.size())
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
			else
				cout << "0\n";
		}
		else
			pq.push(m);
	}
}
