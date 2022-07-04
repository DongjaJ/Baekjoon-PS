#include <bits/stdc++.h>
using namespace std;

int ch[40], ch2[40], ch3[40];

int N;
int cnt = 0;

void func(int x)
{
	if (x == N)
	{
		cnt++;
		return;
	}

	// cout << n << ' ';

	for (int y = 0; y < N; y++)
	{
		if (!ch[y] && !ch2[x + y] && !ch3[x - y + N - 1])
		{
			ch[y] = 1;
			ch2[x + y] = 1;
			ch3[x - y + N - 1] = 1;
			func(x + 1);
			ch[y] = 0;
			ch2[x + y] = 0;
			ch3[x - y + N - 1] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	func(0);

	cout << cnt;
}
