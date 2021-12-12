#include <bits/stdc++.h>
using namespace std;

int d[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0] = 0;
    d[1] = 1;
    int n;
    cin >> n;

    if (n == 0 || n == 1)
    {
        cout << n << '\n';
        cout << d[n];
        return 0;
    }
    if (n > 0)
    {
        cout << 1 << '\n';
        for (int i = 2; i <= n; i++)
        {
            d[i] = (d[i - 1] % 1000000000 + d[i - 2] % 1000000000) % 1000000000;
        }
        cout << d[n];
        return 0;
    }

    d[1999999] = 1;
    d[1999998] = -1;
    for (int i = -2; i >= n; i--)
    {
        d[i + 2000000] = (d[i + 2000002] % 1000000000 - d[i + 2000001] % 1000000000) % 1000000000;
    }
    if (d[n + 2000000] > 0)
        cout << 1 << '\n';
    else
        cout << -1 << '\n';
    cout << abs(d[n + 2000000]) % 1000000000;
}