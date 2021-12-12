#include <bits/stdc++.h>
using namespace std;

int t[20];
int p[20];

int n;

int mx = 0;
void func(int k, int cnt)
{
    if (k > n)
        return;
    if (k == n)
    {
        mx = max(mx, cnt);
        return;
    }

    func(k + 1, cnt);
    func(k + t[k], cnt + p[k]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i] >> p[i];
    func(0, 0);

    cout << mx;
}