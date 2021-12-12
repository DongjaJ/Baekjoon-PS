#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int mx = 0;
int a[20];
int b[20];
int mina = 0;
int minb = 0;
int isused[20];
int n;

void func(int k, int s)
{
    if (k == n)
    {
        mx = max(cnt, mx);
        cnt = 0;
        return;
    }

    if (s == n && cnt == n - 1)
    {
        func(k + 1);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isused[i])
            continue;
        if (mina < a[i] || minb > b[i])
        {
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    func(0);
}