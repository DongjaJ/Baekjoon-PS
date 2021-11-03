#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
int unused[10];

void func(int k, int s)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
    }

    for (int i = s; i < n; i++)
    {
        if (unused[i])
            continue;
        unused[i] = 1;
        arr[k] = num[i];
        func(k + 1, i);
        unused[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);
    func(0, 0);
}