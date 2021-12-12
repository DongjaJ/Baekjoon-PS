#include <bits/stdc++.h>
using namespace std;

int ch = 0; // 1 java 2 c++

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v;

    string s;

    cin >> s;
    if (s[0] < 'a' || s[0] > 'z' || s[s.size() - 1] == '_')
    {
        cout << "Error!";
        return 0;
    }

    int i = 1;
    while (i < s.size())
    {
        if (s[i] <= 'z' && s[i] >= 'a')
        {
            i++;
            continue;
        }

        // java
        else if (s[i] <= 'Z' && s[i] >= 'A')
        {
            if (ch == 2)
            {
                ch = 0;
                break;
            }

            ch = 1;

            s[i] = tolower(s[i]);

            s.insert(i++, "_");
        }

        // c++
        else if (s[i] == '_')
        {
            if (ch == 1)
            {
                ch = 0;
                break;
            }

            if (++i == s.size() || s[i] < 'a' || s[i] > 'z')
            {
                ch = 0;
                break;
            }

            ch = 2;

            s[i] = toupper(s[i]);
            s.replace(s.find("_"), 1, "");
        }

        else
            break;
    }

    if (ch == 0 && i != s.size())
        cout << "Error!";

    else
        cout << s;
}