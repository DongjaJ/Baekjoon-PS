#include <bits/stdc++.h>
using namespace std;

int n, mn = 10000000;

int a[100001];
int s;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // cout << a[i] << ' ';
    }

    int en = 0, total = a[0];
    for (int i = 0; i < n; i++)
    {
        while (en < n && total < s)
        {
            en++;
            if (en < n)
                total += a[en];
        }
        if (en == n)
            break;
        mn = min(mn, en - i + 1);
        // cout << mn << ' ';
        total -= a[i];
    }
    if (mn == 10000000)
        mn = 0;
    cout << mn;
}