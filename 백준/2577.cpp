#include <bits/stdc++.h>

using namespace std;

int v[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, result = 1;
    for (int i = 0; i < 3; i++)
    {
        cin >> n;
        result *= n;
    }

    while (result > 0)
    {
        v[result % 10]++;
        result /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << "\n";
    }
}