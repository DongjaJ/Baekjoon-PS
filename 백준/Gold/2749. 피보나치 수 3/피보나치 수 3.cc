#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> mul(vector<vector<long long>> x, vector<vector<long long>> y)
{
	vector<vector<long long>> tmp(2, vector<long long>(2));
	tmp[0][0] = (x[0][0] * y[0][0] + x[0][1] * y[1][0]) % 1000000;
	tmp[0][1] = (x[0][0] * y[0][1] + x[0][1] * y[1][1]) % 1000000;
	tmp[1][0] = (x[1][0] * y[0][0] + x[1][1] * y[1][0]) % 1000000;
	tmp[1][1] = (x[1][0] * y[0][1] + x[1][1] * y[1][1]) % 1000000;
	return tmp;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;

	vector<vector<long long>> A = {{1, 1}, {1, 0}};
	vector<vector<long long>> B = {{1, 0}, {0, 1}};

	cin >> n;
	if (n < 2)
	{
		cout << n;
		return 0;
	}
	n--;
	for (long long i = n; i > 0; i /= 2)
	{
		if (i & 1)
		{
			B = mul(B, A);
		}
		A = mul(A, A);
	}
	cout << B[0][0] << '\n';
}
