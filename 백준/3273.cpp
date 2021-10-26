#include <bits/stdc++.h>

using namespace std;

int a[2000001];
int tmp[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> tmp[i];
    }

    int x;
    cin >> x;

    int result = 0;
    for (int i = 0; i < c; i++)
    {
        if (a[x - tmp[i]])
            result++;
        a[tmp[i]]++;
    }
    cout << result;
}