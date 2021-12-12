#include <bits/stdc++.h>
using namespace std;

int n, m;

int a[500000];
int b[500000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (binary_search(b, b + m, a[i]))
            continue;
        v.push_back(a[i]);
    }
    if (v.empty())
        cout << 0;
    else
    {
        cout << v.size() << '\n';
        for (auto &i : v)
            cout << i << ' ';
    }
}