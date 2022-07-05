#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> v2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	v2.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		v2[i] = v[i];
	}

	sort(v2.begin(), v2.end());
	v2.erase(unique(v2.begin(), v2.end()), v2.end());
	for (auto i : v)
		cout << lower_bound(v2.begin(), v2.end(), i) - v2.begin() << ' ';
}
