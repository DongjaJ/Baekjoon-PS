#include <bits/stdc++.h>

using namespace std;

int a[5];

int x, y;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> y;
	if (x == y)
	{
		cout << -1;
		return 0;
	}

	long long now = 100 * (long long)y / x;

	if (now == 99)
	{
		cout << -1;
		return 0;
	}

	// cout << "now " << now << '\n';
	long long st = 1, en = 1;
	while (1)
	{
		long long tmp = 100 * (en + y) / (en + x);
		if (tmp != now)
			break;
		en *= 2;
	}

	while (st < en)
	{
		// cout << st << ' ' << en << '\n';
		long long mid = (st + en) / 2;
		long long tmp = 100 * (mid + y) / (mid + x);
		if (tmp != now)
			en = mid;
		else
			st = mid + 1;
	}

	cout << st;
}
