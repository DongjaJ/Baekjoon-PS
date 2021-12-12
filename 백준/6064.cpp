#include <bits/stdc++.h>
using namespace std;

int m, n, x, y;

int lcd()
{
    return m / gcd(m, n) * n;
}

int solve()
{
    if (x == m)
        x = 0;
    if (y == n)
        y = 0;
    int ls = lcd();

    for (int i = x; i < ls; i += m)
    {
        if (i == 0)
            continue;
        if (i % n == y)
            return i;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        bool ch = true;
        cin >> m >> n >> x >> y;
        cout << solve() << '\n';
    }
}