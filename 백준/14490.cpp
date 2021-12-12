#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    string s, num = "", ans = "";
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ':')
        {
            a = stoi(num);
            num = "";
        }
        else
        {
            num += s[i];
        }
    }
    b = stoi(num);
    int c = gcd(a, b);
    ans += to_string(a / c);
    ans += ":";
    ans += to_string(b / c);
    cout << ans;
}