#include <bits/stdc++.h>
using namespace std;

int d[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    d[0] = 1;
    d[1] = 0;
    d[2] = 1;
    d[3] = 0;
    int n;
    cin >> n;
    if (n >= 4)
    {
        for (int i = 0; i < n; i++)
        {
            if (min(d[i - 1], d[i - 3]) == 1)
                d[i] = 0;
            else
                d[i] = 1;
        }
    }
    if (d[n - 1])
        cout << "SK";
    else
        cout << "CY";
}