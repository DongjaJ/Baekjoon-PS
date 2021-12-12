#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int tmp[10];
int isused[10];

void func(int k, int s)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int b = -1;
    for (int i = s; i < n; i++)
    {
        if (i != 0 && b == tmp[i])
            continue;
        b = tmp[i];
        arr[k] = tmp[i];
        func(k + 1, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> tmp[i];

    sort(tmp, tmp + n);
    func(0, 0);
}