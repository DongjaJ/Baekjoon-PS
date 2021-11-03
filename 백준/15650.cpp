#include <bits/stdc++.h>
using namespace std;

int n, m;
int unused[9];
int arr[9];

void func(int x, int start)
{
    if (x == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++)
    {
        if (unused[i])
            continue;
        arr[x] = i;
        unused[i] = 1;
        func(x + 1, i);
        unused[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0, 1);
}