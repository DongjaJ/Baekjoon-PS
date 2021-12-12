#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &s1, const string &s2)
{
    if (s1.size() != s2.size())
        return s1.size() < s2.size();
    return s1 < s2;
}

string s[20000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n, cmp);

    cout << s[0] << '\n';
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            continue;
        cout << s[i] << '\n';
    }
}