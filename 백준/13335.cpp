#include <bits/stdc++.h>
using namespace std;

int n, w, l;
int truc[1000];

int bridge[100];

void go()
{
    for (int i = w - 1; i > 0; i--)
        bridge[i] = bridge[i - 1];
    bridge[0] = 0;
}

int cnt()
{
    int sum = 0;
    for (int i = 0; i < w; i++)
        sum += bridge[i];
    return sum;
}

void print()
{
    for (int i = 0; i < w; i++)
        cout << bridge[i] << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;

    for (int i = 0; i < n; i++)
        cin >> truc[i];

    int t = 0, idx = 0;
    while (1)
    {

        if (cnt() == 0 && idx == n)
            break;
        t++;
        go();
        if (idx == n)
            continue;
        if (cnt() + truc[idx] <= l)
            bridge[0] = truc[idx++];

        // print();
    }

    cout << t;
}