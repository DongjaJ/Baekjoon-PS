#include <bits/stdc++.h>
using namespace std;

stack<int> s;
long long n, cnt = 0;

int h;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h;

        while (!s.empty() && s.top() <= h)
            s.pop();

        cnt += s.size();

        s.push(h);
    }

    cout << cnt;
}