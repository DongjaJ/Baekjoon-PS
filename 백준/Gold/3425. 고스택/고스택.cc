#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int start = 0;

	while (1)
	{
		vector<string> cmd_array;
		while (1)
		{
			string cmd;
			cin >> cmd;
			if (cmd == "QUIT")
				return 0;
			if (cmd == "END")
				break;
			if (cmd == "NUM")
			{
				string n;
				cin >> n;
				cmd += " ";
				cmd += n;
			}
			cmd_array.push_back(cmd);
		}
		if (start)
			cout << '\n';

		int t;
		cin >> t;
		while (t--)
		{
			stack<int> s;
			int n;
			cin >> n;
			s.push(n);

			int flag = 0;
			for (int i = 0; i < cmd_array.size(); i++)
			{
				if (cmd_array[i].find("NUM") == 0)
				{
					int token = stoi(cmd_array[i].substr(4));
					s.push(token);
				}
				else if (cmd_array[i] == "POP")
				{
					if (s.empty())
					{
						flag++;
						break;
					}
					s.pop();
				}
				else if (cmd_array[i] == "INV")
				{
					if (s.empty())
					{
						flag++;
						break;
					}
					int tmp = s.top();
					s.pop();
					tmp *= -1;
					s.push(tmp);
				}
				else if (cmd_array[i] == "DUP")
				{
					if (s.empty())
					{
						flag++;
						break;
					}
					s.push(s.top());
				}
				else if (cmd_array[i] == "SWP")
				{
					if (s.size() < 2)
					{
						flag++;
						break;
					}
					int tmp1 = s.top();
					s.pop();
					int tmp2 = s.top();
					s.pop();
					s.push(tmp1);
					s.push(tmp2);
				}
				else if (cmd_array[i] == "ADD")
				{
					if (s.size() < 2)
					{
						flag++;
						break;
					}
					int tmp1 = s.top();
					s.pop();
					int tmp2 = s.top();
					s.pop();
					long long tmp = tmp1 + tmp2;
					if (abs(tmp) > 1000000000)
					{
						flag++;
						break;
					}
					s.push(tmp);
				}
				else if (cmd_array[i] == "SUB")
				{
					if (s.size() < 2)
					{
						flag++;
						break;
					}
					int tmp1 = s.top();
					s.pop();
					int tmp2 = s.top();
					s.pop();
					long long tmp = tmp2 - tmp1;
					if (abs(tmp) > 1000000000)
					{
						flag++;
						break;
					}
					s.push(tmp);
				}
				else if (cmd_array[i] == "MUL")
				{
					if (s.size() < 2)
					{
						flag++;
						break;
					}
					int tmp1 = s.top();
					s.pop();
					int tmp2 = s.top();
					s.pop();
					long long tmp = tmp2 * tmp1;
					if (tmp2 != 0 && abs(tmp1) > abs(1000000000 / tmp2))
					{
						flag++;
						break;
					}
					s.push((int)tmp);
				}
				else if (cmd_array[i] == "DIV")
				{
					int minus = 1;
					if (s.size() < 2)
					{
						flag++;
						break;
					}
					int tmp1 = s.top();
					s.pop();
					int tmp2 = s.top();
					s.pop();
					if (tmp1 == 0)
					{
						flag++;
						break;
					}
					if (tmp1 < 0)
					{
						tmp1 *= -1;
						minus *= -1;
					}
					if (tmp2 < 0)
					{
						tmp2 *= -1;
						minus *= -1;
					}
					long long tmp = tmp2 / tmp1;
					if (abs(tmp) > 1000000000)
					{
						flag++;
						break;
					}
					s.push((int)tmp * minus);
				}
				else if (cmd_array[i] == "MOD")
				{
					int minus = 1;
					if (s.size() < 2)
					{
						flag++;
						break;
					}
					int tmp1 = s.top();
					s.pop();
					int tmp2 = s.top();
					s.pop();
					if (tmp1 == 0)
					{
						flag++;
						break;
					}
					if (tmp1 < 0)
					{
						tmp1 *= -1;
					}
					if (tmp2 < 0)
					{
						minus *= -1;
						tmp2 *= -1;
					}
					long long tmp = tmp2 % tmp1;
					if (abs(tmp) > 1000000000)
					{
						flag++;
						break;
					}
					s.push((int)tmp * minus);
				}
			}
			if (flag || s.size() != 1)
				cout << "ERROR\n";
			else
				cout << s.top() << '\n';
			start++;
		}
	}
}
