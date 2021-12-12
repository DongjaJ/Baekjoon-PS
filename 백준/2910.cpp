#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n, c;

map<int, int> m;
map<int, int> order;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return order[a.second] < order[b.second];

    return a.first > b.first;
}

//fre, idx, item
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
        if (order[x] == 0)
            order[x] = i + 1;
    }

    for (auto i : m)
        v.emplace_back(i.second, i.first);

    sort(v.begin(), v.end(), cmp);

    for (auto i : v)
        for (int j = 0; j < i.first; j++)
            cout << i.second << ' ';
}