#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    list<char> L;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        L.push_back(s[i]);
    }
    list<char>::iterator t = L.end();
    // for (list<char>::iterator it = L.begin(); it != L.end(); it++)
    //     cout << *it << " ";
    int c;
    cin >> c;
    cin.ignore();
    while (c--)
    {
        string ss;
        getline(cin, ss);
        if (ss[0] == 'L')
        {
            if(t != L.begin()) t--;
        }
        else if (ss[0] == 'D')
        {
            if(t != L.end())
                t++;
        }
        else if (ss[0] == 'B')
        {
            if(t != L.begin())
                t = L.erase(--t);
        }
        else
        {
            L.insert(t, ss[2]);
        }
    }

    for (t = L.begin(); t != L.end(); t++)
    {
        cout << *t;
    }
}
