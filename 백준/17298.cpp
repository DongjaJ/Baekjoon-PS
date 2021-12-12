#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000000];
int N[1000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!s.empty() && s.top() <= a[i])
            s.pop();

        if (s.empty())
            N[i] = -1;
        else
            N[i] = s.top();
        s.push(a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << N[i] << ' ';
}