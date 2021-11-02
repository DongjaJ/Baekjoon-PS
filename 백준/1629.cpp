#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll func(ll x, ll y, ll z)
{
    if (y == 1)
        return x % z;
    ll tmp = func(x, y / 2, z);
    tmp = tmp * tmp % z;
    if (y % 2 == 0)
        return tmp;
    return tmp * x % z;
}

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);
}

// int func(long long a, long long b, long long c)
// {
//     if (b == 1)
//         return a % c;
//     long long tmp = func(a, b / 2, c);
//     tmp = tmp * tmp % c;
//     if (b % 2 == 0)
//         return tmp;
//     return tmp * a % c;
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     long long a, b, c;
//     cin >> a >> b >> c;
//     cout << func(a, b, c);
// }