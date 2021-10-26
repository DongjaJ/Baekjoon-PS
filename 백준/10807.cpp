#include <bits/stdc++.h>

using namespace std;
int a[201];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int v;
    cin >> v;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == v)
            result++;
    }
    cout << result;
}