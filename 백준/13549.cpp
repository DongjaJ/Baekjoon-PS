#include <bits/stdc++.h>
using namespace std;

int a[100001];
int d[2] = {-1, 1};
int n, k;

int bfs()
{
    queue<int> q;
    q.push(n);
    a[n] = 0;

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            cout << tmp << '\n';
            if (tmp == k)
                return a[k];
            if (i == 0)
            {
                if (2 * tmp > 100)
                    continue;
                if (a[2 * tmp] != -1 && a[2 * tmp] <= a[tmp])
                    continue;
                q.push(tmp * 2);
                a[tmp * 2] = a[tmp];
                continue;
            }
            int nx = tmp + d[i - 1];
            if (nx < 0 && nx > 101)
                continue;
            if (a[nx] != -1 && a[nx] <= a[tmp] + 1)
                continue;
            a[nx] = a[tmp] + 1;
            q.push(nx);
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(a, a + 100001, -1);

    cin >> n >> k;

    cout << bfs();
}