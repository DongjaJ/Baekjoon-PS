#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int arr[10];
int unused[10];
int n, m;

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (unused[i])
            continue;
        arr[k] = v[i];
        unused[i] = 1;
        func(k + 1);
        unused[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    func(0);
}