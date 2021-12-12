#include <bits/stdc++.h>
using namespace std;

int n;
int s[10];
int w[10];
int mx = 0;
int cnt = 0;

void func(int k)
{
    if (n == k)
    {
        mx = max(mx, cnt);
        return;
    }

    if (s[k] <= 0 || cnt == n - 1)
    {
        func(k + 1);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == k || s[i] <= 0)
            continue;
        s[i] -= w[k];
        s[k] -= w[i];
        if (s[i] <= 0)
            cnt++;
        if (s[k] <= 0)
            cnt++;
        func(k + 1);
        if (s[i] <= 0)
            cnt--;
        if (s[k] <= 0)
            cnt--;

        s[i] += w[k];
        s[k] += w[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i] >> w[i];
    func(0);
    cout << mx;
}