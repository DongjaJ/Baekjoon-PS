#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32001];
vector<int> ans;
int deg[32001];

void solve()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
            q.push(i);
    }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for (auto i : adj[x])
        {
            deg[i]--;
            if (deg[i] == 0)
                q.push(i);
        }
    }

    for (auto i : ans)
        cout << i << ' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int st, en;
        cin >> st >> en;
        adj[st].push_back(en);
        deg[en]++;
    }

    solve();
}