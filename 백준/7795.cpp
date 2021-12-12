#include <bits/stdc++.h>
using namespace std;
int n, m, t, a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> v;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back({a, 0});
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b;
            v.push_back({b, 1});
        }

        sort(v.begin(), v.end());

        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n + m; i++)
        {
            if (v[i].second == 0)
                ans += cnt;
            else
                cnt++;
        }

        cout << ans << '\n';
    }
}