#include <bits/stdc++.h>
using namespace std;

int n, m;

int a[1000000];

int bs()
{
    int st = 0, en = 1000000000;
    while (st < en)
    {
        int mid = (st + en) / 2 + 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += a[i] / mid;
        if (cnt >= m)
            st = mid;
        else
            en = mid - 1;
    }

    return st;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << bs();
}