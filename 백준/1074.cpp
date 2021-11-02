#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c)
{
    if (n == 0)
        return 0;
    int half = 1 << (n - 1);

    if (r < half && c < half)
        return func(n - 1, r, c);
    if (r < half && c >= half)
        return half * half + func(n - 1, r, c - half);
    if (r >= half && c < half)
        return half * half * 2 + func(n - 1, r - half, c);
    return half * half * 3 + func(n - 1, r - half, c - half);
}

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}

// int func(int r, int c, int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     int half = 1 << (n - 1);
//     if (r < half && c < half)
//         return func(r, c, n - 1);
//     if (r < half && c >= half)
//         return half * half + func(r, c - half, n - 1);
//     if (r >= half && c < half)
//         return half * half * 2 + func(r - half, c, n - 1);
//     return half * half * 3 + func(r - half, c - half, n - 1);
// }

// int main()
// {
//     int n, r, c;
//     cin >> n >> r >> c;
//     cout << func(r, c, n);
// }