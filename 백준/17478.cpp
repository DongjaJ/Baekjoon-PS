#include <iostream>

using namespace std;

int k;

void func(int n)
{
    if (n == k)
    {
        for (int i = 0; i < 4 * n; i++)
            cout << "_";
        cout << "\"����Լ��� ������?\"\n";
        for (int i = 0; i < 4 * n; i++)
            cout << "_";
        cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        for (int i = 0; i < 4 * n; i++)
            cout << "_";
        cout << "��� �亯�Ͽ���.\n";
        return;
    }

    for (int i = 0; i < 4 * n; i++)
        cout << "_";
    cout << "\"����Լ��� ������?\"\n";
    for (int i = 0; i < 4 * n; i++)
        cout << "_";
    cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    for (int i = 0; i < 4 * n; i++)
        cout << "_";
    cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    for (int i = 0; i < 4 * n; i++)
        cout << "_";
    cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    func(n + 1);
    for (int i = 0; i < 4 * n; i++)
        cout << "_";
    cout << "��� �亯�Ͽ���.\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    func(0);
}