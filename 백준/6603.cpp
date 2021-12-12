#include <bits/stdc++.h>
using namespace std;

int arr[15];
int num[15];
int isused[15];
void func(int k, int n, int s)
{
    if (n == 6)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = s; i < k; i++)
    {
        if (isused[i])
            continue;
        arr[n] = num[i];
        isused[i] = 1;
        func(k, n + 1, i);
        isused[i] = 0;
    }
}

int main()
{
    int N;
    cin >> N;
    while (N)
    {
        for (int i = 0; i < N; i++)
            cin >> num[i];
        sort(num, num + N);
        func(N, 0, 0);
        cout << '\n';
        cin >> N;
    }
}