#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    while (k--)
    {
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            q.push({tmp, i});
            pq.push(tmp);
        }

        int cnt = 0;
        while (!q.empty())
        {
            int val = q.front().first;
            int ind = q.front().second;
            q.pop();
            if (val == pq.top())
            {
                cnt++;
                pq.pop();
                if (ind == m)
                {
                    cout << cnt << '\n';
                    break;
                }
            }
            else
            {
                q.push({val, ind});
            }
        }
    }
}