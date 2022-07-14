#include <bits/stdc++.h>
using namespace std;

int n, m;

int d[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        d[i] = d[i - 1] + tmp;
    }

    // for (int i = 0; i <= n; i++)
    //     cout << d[i] << ' ';

    while (m--)
    {
        int s, e;
        cin >> s >> e;
        cout << d[e] - d[s - 1] << '\n';
    }
}