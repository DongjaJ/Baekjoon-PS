#include <bits/stdc++.h>
using namespace std;
bool n[7500001];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;

    cin >> k;

    for (int i = 2; i <= sqrt(7500000) + 1; i++)
    {
        if (!n[i])
        {
            for (int j = i * i; j <= 7500000; j += i)
            {
                n[j] = true;
            }
        }
    }

    // for (int i = 10; i < 100; i++)
    // {
    //     cout << i << ' ' << n[i] << '\n';
    // }

    for (int i = 2; i <= 7500000; i++)
    {
        if (!n[i])
            v.push_back(i);
    }

    cout << v[k - 1];
}