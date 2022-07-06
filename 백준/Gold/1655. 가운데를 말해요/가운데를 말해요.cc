#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> minq;
    priority_queue<int> maxq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (maxq.empty())
        {
            maxq.push(x);
            cout << x << '\n';
            continue;
        }
        else if (minq.empty())
        {
            minq.push(x);
        }
        else if (minq.size() == maxq.size())
        {
            maxq.push(x);
        }
        else
        {
            minq.push(x);
        }

        if (maxq.top() > minq.top())
        {
            int a = minq.top();
            minq.pop();
            int b = maxq.top();
            maxq.pop();
            minq.push(b);
            maxq.push(a);
        }

        cout << maxq.top() << '\n';
    }
}