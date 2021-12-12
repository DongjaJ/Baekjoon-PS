#include <bits/stdc++.h>
using namespace std;

int a[1000000], b[1000000], c[1000000];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int ai = 0, bi = 0;

    for (int i = 0; i < n + m; i++)
    {
        if (ai == n)
            c[i] = b[bi++];
        else if (bi == m)
            c[i] = a[ai++];

        else if (a[ai] <= b[bi])
            c[i] = a[ai++];
        else
            c[i] = b[bi++];
    }

    for (int i = 0; i < n + m; i++)
        cout << c[i] << ' ';
}