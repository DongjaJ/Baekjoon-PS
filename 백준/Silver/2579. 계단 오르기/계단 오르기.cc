#include <bits/stdc++.h>
using namespace std;

int n;
int step[305];
long long d[305];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> step[i];

	d[1] = step[1];
	d[2] = step[1] + step[2];

	for (int i = 3; i <= n; i++)
	{
		d[i] = max(d[i - 2] + step[i], d[i - 3] + step[i] + step[i - 1]);
	}

	cout << d[n];
}
