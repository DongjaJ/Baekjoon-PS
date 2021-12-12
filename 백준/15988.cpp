#include <bits/stdc++.h>
using namespace std;

long long d[1000001];
int main()
{
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (long long i = 4; i <= 1000000; i++)
    {
        d[i] = (d[i - 1] % 1000000009 + d[i - 2] % 1000000009 + d[i - 3] % 1000000009) % 1000000009;
    }

    long long n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        cout << d[n] % 1000000009 << '\n';
    }
}