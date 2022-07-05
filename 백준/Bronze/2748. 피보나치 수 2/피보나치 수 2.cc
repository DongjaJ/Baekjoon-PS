#include <iostream>
using namespace std;

long long int a[91];

int main()
{
	long long int n;
	cin >> n;
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	cout << a[n];
}
