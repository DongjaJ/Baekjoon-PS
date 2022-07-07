#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >> d;

	int aa = a * d + b * c;
	int bb = b * d;

	int tmp = gcd(aa, bb);

	aa /= tmp;
	bb /= tmp;

	cout << aa << ' ' << bb << '\n';
}
