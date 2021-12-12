#include <bits/stdc++.h>
using namespace std;

int n;

long long int a[1000000];
long long p[15];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    p[0] = 1;
    for (int i = 1; i < 12; i++)
        p[i] = p[i - 1] * 10;
    for (long long i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        long long sz = s.size();
        for (long long j = 0; j < sz; j++)
        {
            a[i] += (s[j] - '0') * p[j];
        }
    }

    sort(a, a + n);

    for (long long i = 0; i < n; i++)
        cout << a[i] << '\n';
}