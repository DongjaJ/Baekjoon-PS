#include <bits/stdc++.h>
using namespace std;

int n;
int arr[21][21];
vector<int> v;
int mn = 1000000000;

void func()
{
    vector<int> v(n, 1);
    fill(v.begin(), v.begin() + n / 2, 0);
    do
    {
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (v[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (v[j])
                        cnt1 += arr[i][j];
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                    if (!v[j])
                        cnt2 += arr[i][j];
            }
        }

        mn = min(mn, abs(cnt1 - cnt2));
        if (mn == 0)
            break;
    } while (next_permutation(v.begin(), v.end()));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    func();

    cout << mn;
}