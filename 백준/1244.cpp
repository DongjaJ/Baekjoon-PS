#include <bits/stdc++.h>
using namespace std;

int a[101];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, ind;
        cin >> s >> ind;
        if (s == 1)
        {
            for (int j = ind; j <= n; j += ind)
            {
                if (a[j] == 1)
                    a[j] = 0;
                else
                    a[j] = 1;
            }
        }
        else
        {
            int start = ind, end = ind;
            while (1)
            {
                if (start <= 0 || end > n)
                    break;
                if (a[start] != a[end])
                    break;
                if (a[start] == 0)
                {
                    a[start] = a[end] = 1;
                }
                else
                {
                    a[start] = a[end] = 0;
                }
                start--;
                end++;
            }
        }
        }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
}