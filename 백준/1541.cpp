#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    string s;
    bool isminus = false;
    cin >> s;
    string num = "";

    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || i == s.size())
        {
            if (isminus)
            {

                sum -= stoi(num);
            }
            else
                sum += stoi(num);

            num = "";
        }
        else
        {
            num += s[i];
        }

        if (s[i] == '-')
        {
            isminus = true;
        }
    }
    cout << sum;
}
