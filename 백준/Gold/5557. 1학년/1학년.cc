#include <bits/stdc++.h>

using namespace std;
int arr[100];

long long d[105][50];

int N;

long long func(int n, int sum)
{
	if (n == 0)
	{
		if (sum == arr[0])
			return 1;
		else
			return 0;
	}

	if (d[n][sum] != -1)
		return d[n][sum];

	long long ans = 0;
	int p = sum + arr[n], m = sum - arr[n];
	if (p >= 0 && p <= 20)
		ans += func(n - 1, p);
	if (m >= 0 && m <= 20)
		ans += func(n - 1, m);

	return d[n][sum] = ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i <= 105; i++)
		fill(d[i], d[i] + 50, -1);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cout << func(N - 2, arr[N - 1]);
}
