#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> t;
    while (t--)
    {
        deque<int> dq;
        string s, num, cmd;
        cin >> cmd;
        cin >> n;
        cin >> s;

        if (n > 0)
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '[')
                    continue;
                else if ((s[i] == ',' || s[i] == ']') && num != "")
                {
                    dq.push_back(stoi(num));
                    num = "";
                }
                else
                    num += s[i];
            }
        }

        int st = 0;
        int ch = true;
        for (int i = 0; i < cmd.size(); i++)
        {
            if (cmd[i] == 'R')
                st = 1 - t;

            else
            {
                if (!dq.size())
                {
                    ch = false;
                    cout << "error\n";
                    break;
                }
                if (st == 0)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (st)
            reverse(dq.begin(), dq.end());
        if (ch)
        {
            string res = "";
            if (!dq.size())
                res = "[]\n";
            else
            {
                res += ("[" + to_string(dq[0]));
                for (int i = 1; i < dq.size(); i++)
                    res += ("," + to_string(dq[i]));
                res += "]\n";
            }
            cout << res;
        }
    }
}