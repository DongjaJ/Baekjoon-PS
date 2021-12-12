#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    string ans;
    ans = s1.size() >= s2.size() ? "go" : "no";
    cout << ans;
}