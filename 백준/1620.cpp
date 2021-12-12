#include <bits/stdc++.h>
using namespace std;

string arr[100000];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (m--)
    {
        string s;
        cin >> s;
        if (isdigit(s[0]))
        {
            int ind = stoi(s);
            cout << arr[ind - 1] << '\n';
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == s)
                    cout << i + 1 << '\n';
            }
        }
    }
}