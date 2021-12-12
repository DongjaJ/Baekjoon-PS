#include <bits/stdc++.h>
using namespace std;

int n;
int arr[101];
int v[4];
//vector<int> v;

int mn = 100000000;
int mx = -10000000;

// 0 + 1 - 2 * 3 /

// void func()
// {

//     do
//     {
//         /* code */
//         int cnt = a[0];
//         for (int i = 0; i < n - 1; i++)
//         {
//             if (v[i] == 0)
//             {
//                 cnt += a[i + 1];
//             }
//             else if (v[i] == 1)
//             {
//                 cnt -= a[i + 1];
//             }
//             else if (v[i] == 2)
//             {
//                 cnt *= a[i + 1];
//             }
//             else
//             {
//                 cnt /= a[i + 1];
//             }
//         }
//         mx = max(mx, cnt);
//         mn = min(mn, cnt);

//     } while (next_permutation(v.begin(), v.end()));
// }

void func2(int a, int b, int c, int d, int k, int cal)
{
    if (n == k)
    {
        if (mx < cal)
            mx = cal;
        if (mn > cal)
            mn = cal;
        return;
    }

    if (a > 0)
        func2(a - 1, b, c, d, k + 1, cal + arr[k]);
    if (b > 0)
        func2(a, b - 1, c, d, k + 1, cal - arr[k]);
    if (c > 0)
        func2(a, b, c - 1, d, k + 1, cal * arr[k]);
    if (d > 0)
        func2(a, b, c, d - 1, k + 1, cal / arr[k]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < 4; i++)
        cin >> v[i];
    // for (int i = 0; i < 4; i++)
    // {
    //     int tmp;
    //     cin >> tmp;
    //     while (tmp--)
    //         v.push_back(i);
    // }

    // func();

    func2(v[0], v[1], v[2], v[3], 1, arr[0]);

    cout << mx << '\n';
    cout << mn;
}