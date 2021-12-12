#include <bits/stdc++.h>
using namespace std;

int a[500001];
int n, m;

int ubs(int tmp)
{
    int st = 0, en = n;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (a[mid] > tmp)
            en = mid;
        else
            st = mid + 1;
    }
    return st;
}

int lbs(int tmp)
{
    int st = 0, en = n;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (a[mid] >= tmp)
            en = mid;
        else
            st = mid + 1;
    }
    return st;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    cin >> m;

    while (m--)
    {
        int tmp;
        cin >> tmp;
        // cout << ubs(tmp) - lbs(tmp) << ' ';
        cout << upper_bound(a, a + n, tmp) - lower_bound(a, a + n, tmp) << ' ';
    }
}