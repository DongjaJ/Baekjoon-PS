#include <bits/stdc++.h>
using namespace std;

int l, c;
char arr[20];
char ch[20];
int isused[20];

//모음, 자음
void func(int k, int s, int check1, int check2)
{
    if (k == l)
    {
        if (check1 && check2 >= 2)
        {
            for (int i = 0; i < l; i++)
                cout << arr[i];
            cout << '\n';
        }
        return;
    }

    for (int i = s; i < c; i++)
    {
        if (isused[i])
            continue;
        arr[k] = ch[i];
        isused[i] = 1;
        if (arr[k] == 'a' || arr[k] == 'e' || arr[k] == 'i' || arr[k] == 'o' || arr[k] == 'u')
            func(k + 1, i + 1, check1 + 1, check2);
        else
            func(k + 1, i + 1, check1, check2 + 1);
        isused[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++)
        cin >> ch[i];
    sort(ch, ch + c);
    func(0, 0, 0, 0);
}