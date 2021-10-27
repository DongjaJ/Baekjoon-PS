#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    queue<char> q;
    int n;
    cin >> n;
    int flag = true;
    int i = 1;
    while (n--)
    {
        int c;
        cin >> c;
        if (s.empty())
        {
            s.push(i++);
            q.push('+');
        }
        while (s.top() < c)
        {
            s.push(i++);
            q.push('+');
        }
        if (s.top() > c)
        {
            flag = false;
            break;
        }
        else if (s.top() == c)
        {
            s.pop();
            q.push('-');
        }
    }
    if (flag)
    {
        while (!q.empty())
        {
            cout << q.front() << "\n";
            q.pop();
        }
    }
    else
        cout << "NO";
}