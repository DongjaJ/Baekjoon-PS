#include <bits/stdc++.h>
using namespace std;

int a[10000];

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int st = 0, en = 0, tot = a[0], cnt = 0;
    while (1)
    {
        if (tot == m)
            cnt++;
        if (tot <= m)
            tot += a[++en];
        if (tot > m)
            tot -= a[st++];
        if (en == n)
            break;
    }

    cout << cnt;
}