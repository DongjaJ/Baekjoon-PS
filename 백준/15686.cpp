#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int n, m;

void func()
{
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0);

    int mn = 100000000;
    do
    {
        /* code */
        int dist = 0;
        for (auto h : house)
        {
            int tmp = 10000000;
            for (int i = 0; i < chicken.size(); i++)
            {
                if (brute[i] == 0)
                    continue;
                tmp = min(tmp, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
            }
            dist += tmp;
        }
        mn = min(mn, dist);
    } while (next_permutation(brute.begin(), brute.end()));

    cout << mn;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 1)
                house.push_back({i, j});
            else if (tmp == 2)
                chicken.push_back({i, j});
        }
    }

    func();
}