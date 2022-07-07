#include <bits/stdc++.h>

using namespace std;

int arr[1000005];

int n;

vector<int> v;

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

	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		for (auto i : v)
		{
			if (arr[n - i] == 2)
			{
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
	}
}
