#include <bits/stdc++.h>
using namespace std;

int n, m;
int ¤·[30][30];
int cnt = 0;
void func(int k, int s)
{
    if (n == k)
    {
        cnt++;
        // for (int i = 0; i < n; i++)
        //     cout << arr[i] << ' ';
        return;
    }
    for (int i = s; i <= m; i++)
    {
        if (isused[i])
            continue;
        isused[i] = 1;
        func(k + 1, i);
        isused[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i)

        int k;
    cin >> k;
    while (k--)
    {
        cin >> n >> m;
        fill(isused, isused + n, 0);
        cnt = 0;
        func(0, 1);
        cout << cnt;
    }
}