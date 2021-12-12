#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
bool ch[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        fill(ch, ch + 26, false);
        string s;
        cin >> s;
        int i = 0;
        char b = ' ';
        while (i < s.size())
        {
            if (b == s[i])
            {
                i++;
                continue;
            }
            int ind = s[i] - 'a';
            if (ch[ind])
                break;
            ch[ind] = true;
            b = s[i];
            i++;
        }

        if (i == s.size())
            cnt++;
    }
    cout << cnt;
}