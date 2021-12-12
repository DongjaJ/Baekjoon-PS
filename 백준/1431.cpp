#include <bits/stdc++.h>
using namespace std;

string a[50];
int n;

bool cmp(string s1, string s2)
{
    if (s1.size() != s2.size())
        return s1.size() < s2.size();

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (isdigit(s1[i]))
            cnt1 += s1[i] - '0';
        if (isdigit(s2[i]))
            cnt2 += s2[i] - '0';
    }
    if (cnt1 != cnt2)
        return cnt1 < cnt2;

    return s1 < s2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        cout << a[i] << '\n';
}