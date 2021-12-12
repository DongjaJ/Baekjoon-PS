#include <bits/stdc++.h>
using namespace std;

int n, m;

int mn = 0x7fffffff;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int en;
    en = 0;
    for (int i = 0; i < n; i++)
    {
        while (en < n && a[en] - a[i] < m)
            en++;
        if (en >= n)
            break;
        mn = min(mn, a[en] - a[i]);
    }

    cout << mn;
}