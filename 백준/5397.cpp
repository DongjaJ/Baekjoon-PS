#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int pre[MX];
char now[MX];
int nxt[MX];
int unused = 1;

void insert(int idx, char item)
{
    now[unused] = iten;
    pre[unused] = idx;
    nxt[unused] = nxt[idx];
    if (nxt[idx] != -1)
        pre[nxt[idx]] = unused;
    nxt[pre[idx]] = unused;
    unused++;
}

void erase(int idx)
{
    nxt[pre[idx]] = nxt[idx];
    if (nxt[idx] != -1)
        pre[nxt[idx]] = pre[idx];
}

void travel()
{
    int c = nxt[0];
    while (c != -1)
    {
        cout << now[c];
        c = nxt[c];
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
}

// void insert(int idx, char item)
// {
//     now[unused] = item;
//     pre[unused] = idx;
//     nxt[unused] = nxt[idx];
//     if (nxt[idx] != -1)
//         pre[nxt[idx]] = unused;
//     nxt[idx] = unused;
//     unused++;
// }

// void erase(int idx)
// {
//     nxt[pre[idx]] = nxt[idx];
//     if (nxt[idx] != -1)
//         pre[nxt[idx]] = pre[idx];
// }

// void travel()
// {
//     int cur = nxt[0];
//     while (cur != -1)
//     {
//         if (now[cur] != 0)
//             cout << now[cur];
//         cur = nxt[cur];
//     }
//     cout << "\n";
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     int t;
//     cin >> t;

//     cin.ignore();

//     while (t--)
//     {
//         fill(pre, pre + MX, -1);
//         fill(nxt, nxt + MX, -1);
//         unused = 1;
//         string s;
//         getline(cin, s);
//         int cursor = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] == '<')
//             {
//                 if (pre[cursor] != -1)
//                     cursor = pre[cursor];
//             }
//             else if (s[i] == '>')
//             {
//                 if (nxt[cursor] != -1)
//                     cursor = nxt[cursor];
//             }
//             else if (s[i] == '-')
//             {
//                 if (pre[cursor] != -1)
//                 {
//                     erase(cursor);
//                     cursor = pre[cursor];
//                 }
//             }
//             else
//             {
//                 insert(cursor, s[i]);
//                 cursor = nxt[cursor];
//             }
//         }
//         travel();
//     }
// }