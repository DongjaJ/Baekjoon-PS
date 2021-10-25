#include <bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
    int n;
    cin >> n;

    if (n == 0)
        cout << 1;
    else
    {
        while (n > 0)
        {
            if (n % 10 == 9)
                a[6]++;
            else
                a[n % 10]++;
            n /= 10;
        }

        if (a[6] % 2 == 0)
            a[6] = a[6] / 2;
        else
            a[6] = a[6] / 2 + 1;
        int im = -1;
        for (int i = 0; i < 10; i++)
        {
            if (im < a[i])
                im = a[i];
        }
        cout << im;
    }
}