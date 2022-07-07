#include <bits/stdc++.h>

using namespace std;

int arr[1000005];

int n, k;

vector<int> v;

string p;

int mod(string p, int k)
{
	int res = 0;
	for (int i = 0; p[i]; i++)
	{
		res = (res * 10 + p[i] - '0') % k;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i <= 1000005; i++)
	{
		if (arr[i])
			continue;
		v.push_back(i);
		arr[i] = 2;
		for (int j = i * 2; j <= 1000005; j += i)
		{
			if (arr[j])
				continue;
			arr[j] = 1;
		}
	}

	cin >> p >> k;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= k)
			break;
		if (!mod(p, v[i]))
		{
			cout << "BAD " << v[i];
			return 0;
		}
	}
	cout << "GOOD";
}
