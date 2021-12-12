#include <bits/stdc++.h>
using namespace std;

int n[10000000];
vector<int> v;
int isused[10];
string tmp = "";

// void func(int k, int n, string numbers)
// {
//     if (k == n)
//     {
//         cout << tmp << '\n';
//         if (tmp == "")
//             return;
//         int t = stoi(tmp);
//         for (int i = 0; i < v.size(); i++)
//         {
//             if (v.at(i) == t)
//             {
//                 tmp = tmp.substr(0, tmp.size() - 1);
//                 return;
//             }
//         }
//         v.push_back(t);
//         tmp = tmp.substr(0, tmp.size() - 1);
//         return;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (isused[i])
//             continue;
//         isused[i] = 1;
//         func(k + 1, n, numbers);
//         tmp += numbers[i];
//         func(k + 1, n, numbers);
//         isused[i] = 0;
//         tmp = "";
//     }
// }

bool check(int n)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == n)
            return false;
    }
    return true;
}
int solution(string numbers)
{
    n[0] = 1;
    n[1] = 1;
    for (int i = 2; i < sqrt(10000000) + 1; i++)
    {
        for (int j = i; j < sqrt(10000000) + 1; j++)
        {
            if (i * j >= 10000000)
                break;
            n[i * j] = 1;
        }
    }

    sort(numbers.begin(), numbers.end());

    do
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            int tmp = stoi(numbers.substr(0, i + 1));
            //겹치는거 없을떄
            if (check(tmp))
                v.push_back(tmp);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    //func(0, numbers.size(), numbers);

    int answer = 0;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
        if (n[v.at(i)] == 0)
            answer++;
    }
    cout << answer;
    return answer;
}

int main()
{
    string num = "17";
    solution(num);
}