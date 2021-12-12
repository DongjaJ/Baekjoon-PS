#include <bits/stdc++.h>
using namespace std;

int N, S;
int cnt = 0;
int a[21];
void func(int n, int s)
{
    if (n == N)
    {
        if (S == s)
            cnt++;
        return;
    }

    func(n + 1, s + a[n]);
    func(n + 1, s);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    func(0, 0);
    if (S)
        cout << cnt;
    else
        cout << cnt - 1;
}