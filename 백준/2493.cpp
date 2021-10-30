#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<pair<int, int>> s;

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        long long int a;
        cin >> a;
        while (!s.empty())
        {
            if (s.top().second > a)
            {
                cout << s.top().first << " ";
                break;
            }
            s.pop();
        }

        if (s.empty())
            cout << "0 ";

        s.push(make_pair(i, a));
    }
}