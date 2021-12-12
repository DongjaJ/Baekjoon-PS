#include <bits/stdc++.h>
using namespace std;

int n;

int a[1000001];
int b[1000001];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < n; i++)
    {
        cout << lower_bound(v.begin(), v.end(), a[i]) - v.begin() << ' ';
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     b[i] = a[i];
    // }
    // sort(a, a + n);
    // v.push_back(a[0]);
    // for (int i = 1; i < n; i++)
    // {
    //     if (a[i] == a[i - 1])
    //         continue;
    //     v.push_back(a[i]);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << lower_bound(v.begin(), v.end(), b[i]) - v.begin() << ' ';
    // }
}