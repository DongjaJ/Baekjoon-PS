#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<bool> v(4000001);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    vector<int> p;

    for (int i = 2; i * i <= 4000000; i++)
    {
        for (int j = i * i; j <= 4000000; j += i)
        {
            v[j] = true;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (!v[i])
            p.push_back(i);
    }

    // for (auto &i : p)
    //     cout << i << ' ';

    int en = 0, tot = p[0];
    for (int i = 0; i < p.size(); i++)
    {
        while (en < p.size() && tot < n)
        {
            en++;
            if (en != p.size())
                tot += p[en];
        }
        if (en == p.size())
            break;

        if (tot == n)
            cnt++;
        tot -= p[i];
    }
    cout << cnt;
}