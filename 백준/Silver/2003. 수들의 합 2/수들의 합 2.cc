#include <bits/stdc++.h>

using namespace std;

int arr[10005];

int N;
long long M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int st = 0, en = 0, tot = arr[en], ans = 0;
	while (1)
	{
		if (tot == M)
			ans++;
		if (tot <= M)
			tot += arr[++en];
		if (tot > M)
			tot -= arr[st++];
		if (en == N)
			break;
	}

	cout << ans;
}
