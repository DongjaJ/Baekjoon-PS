#include <bits/stdc++.h>
using namespace std;

vector<int> ab;
vector<int> cd;

vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ab.push_back(A[i] + B[j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cd.push_back(C[i] + D[j]);

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	// for (auto i : ab)
	// 	cout << i << ' ';
	// cout << '\n';
	// for (auto i : cd)
	// 	cout << i << ' ';
	// cout << '\n';

	int st = 0;
	int en = ab.size() - 1;
	// cout << en << '\n';
	long long cnt = 0;
	while (1)
	{
		// cout << st << ' ' << en << '\n';
		long long tmp = ab[st] + cd[en];
		if (tmp == 0)
		{
			long long cnta = 1, cntb = 1;
			st++;
			en--;
			while (st < ab.size() && ab[st] == ab[st - 1])
			{
				cnta++;
				st++;
			}
			while (en >= 0 && cd[en] == cd[en + 1])
			{
				cntb++;
				en--;
			}
			cnt += cnta * cntb;
		}
		if (tmp > 0)
			en--;
		if (tmp < 0)
			st++;
		if (st >= ab.size() || en < 0)
			break;
	}
	cout << cnt;
}
