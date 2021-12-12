#include <bits/stdc++.h>
using namespace std;

int a[1000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    while (t--)
    {
        long long n, cnt = 0;

        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long mx_value = a[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > mx_value)
                mx_value = a[i];
            cnt += mx_value - a[i];
        }

        cout << cnt << '\n';
    }
}