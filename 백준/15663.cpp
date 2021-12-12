#include <bits/stdc++.h>
using namespace std;

int num[10];
int isused[10];
int arr[10];
int n, m;

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int b = -1;
    for (int i = 0; i < n; i++)
    {
        if (isused[i])
            continue;
        if (i != 0 && b == num[i])
            continue;
        b = num[i];
        arr[k] = num[i];
        isused[i] = 1;
        func(k + 1);
        isused[i] = 0;
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
    func(0);
}