#include <iostream>
#include <vector>
using namespace std;




int main()
{
	int n, k;
	cin >> n >>k;
	vector<int> a(n + 1);
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == 0)
		{
			k--;
			a[i] = 1;
			if (k == 0) cout << i;
			for (int j = 2; i*j <= n; j++)
			{
				if (a[i * j] == 0)
				{
					a[i * j] = 1;
					k--;
					if (k == 0) cout << i * j;
				}
			}
		}
	}

	
}