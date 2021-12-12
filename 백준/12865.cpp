#include <bits/stdc++.h>
using namespace std;

int n, k;

int d[110][100011];

int weight[101];
int val[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> weight[i] >> val[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= weight[i])
                d[i][j] = max(d[i - 1][j], d[i - 1][j - weight[i]] + val[i]);
            else
                d[i][j] = d[i - 1][j];
        }
    }

    cout << d[n][k];
}