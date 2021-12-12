#include <bits/stdc++.h>
using namespace std;

int a[10000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b, c;
    cin >> b >> c;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] -= b;
        cnt++;

        if (a[i] < 0)
            continue;
        cnt += a[i] / c;
        a[i] %= c;
        if (a[i] > 0)
            cnt++;
    }

    cout << cnt;
}