#include <bits/stdc++.h>
using namespace std;

int flo[1000001];
int f, s, g, u, d;
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;
    v.push_back(u);
    v.push_back(-d);
    queue<int> q;

    fill(flo, flo + f + 1, -1);
    flo[s] = 0;
    q.push({s});

    while (q.size())
    {
        int now = q.front();
        q.pop();

        if (now == g)
        {
            cout << flo[g];
            return 0;
        }

        for (int i = 0; i < 2; i++)
        {
            int nx = now + v[i];
            if (nx <= 0 || nx > f)
                continue;
            if (flo[nx] != -1)
                continue;
            flo[nx] = flo[now] + 1;
            q.push({nx});
        }
    }

    cout << "use the stairs\n";
}