#include <bits/stdc++.h>
using namespace std;
#define BASE 1048576
#define TSIZE 2097152

int n;

int itree[TSIZE];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b;
		if (a == 2)
			cin >> c;

		if (a == 1)
		{
			int idx = 1;
			while (idx < TSIZE)
			{
				if (b > itree[idx])
					b -= itree[idx++];
				idx *= 2;
			}
			idx /= 2;
			b = idx - BASE;
			cout << b << '\n';
			c = -1;
		}
		b += BASE;
		while (b)
		{
			itree[b] += c;
			b /= 2;
		}
	}
}
