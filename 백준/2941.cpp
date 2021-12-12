#include <bits/stdc++.h>
using namespace std;

vector<string> v = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for (auto i : v)
    {
        while (1)
        {
            int idx = s.find(i);
            if (idx == string::npos)
                break;
            s.replace(idx, i.size(), "*");
        }
    }

    //cout << s << '\n';
    cout << s.size();
}