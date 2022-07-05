#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[1000005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int st = 0, en = *max_element(arr, arr + n);
	while (st < en)
	{
		int mid = (st + en + 1) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] <= mid)
				continue;
			cnt += (arr[i] - mid);
		}
		if (cnt >= m)
			st = mid;
		else
			en = mid - 1;
	}
	cout << st;
}
