#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int d, bottom, cur, target, non, l, a, tmp;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<vector<int>> tower;
		vector<int> keyval;
		vector<int> levelnum;

		tower.resize(3);
		int n;
		int x = 0;

		cin >> n; //��������
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			levelnum.push_back(a);//������ ����
		}

		cin >> l; //�����
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < levelnum[j]; k++)
			{
				x++; //��� ������ ���� ����
			}
			keyval.push_back(x); //�� ������ ���� ������ ���� ����
			x *= 2;
			//�� ���� ������ �̵��ɶ����� �̵����� �����̵���*2+���� ������ ����
		}

		int b = levelnum.size() - 1;
		cur = 0;
		non = 1;
		target = 2;

		bottom = n - 1;//�̵��� ������ �̵������� ���ϴ� �����Ϳ���

		for (int k = n - 1; k >= 0; k--)
		{
			for (int m = 0; m < levelnum[k]; m++)
			{
				tower[cur].push_back(k + 1);
			}
		}
		while (l != 0) {
			for (int j = b; j >= 0; j--)
			{
				if (l < keyval[0])
				{
					if ((bottom) % 2 == 0) {
						for (int k = 0; k < l; k++)
						{
							tower[cur].pop_back();
							tower[target].push_back(1);
						}
					}
					else {
						tmp = target;
						target = non;
						non = tmp;
						for (int k = 0; k < l; k++)
						{
							tower[cur].pop_back();
							tower[target].push_back(1);
						}
					}
					l = 0;
				}

				d = cur;

				if (l == keyval[j])
				{
					l = l - keyval[j];
					if ((bottom - j) % 2 == 0)
					{
						for (int k = j; k >= 0; k--)
						{
							for (int m = 0; m < levelnum[k]; m++)
							{
								tower[cur].pop_back();
								tower[target].push_back(k + 1);
							}
						}
						bottom = j;
					}
					else {
						tmp = target;
						target = non;
						non = tmp;

						for (int k = j; k >= 0; k--)
						{
							for (int m = 0; m < levelnum[k]; m++)
							{
								tower[cur].pop_back();
								tower[target].push_back(k + 1);
							}
						}
						bottom = j;
					}
					break;
				}
				else if (l > keyval[j])
				{
					l = l - keyval[j];
					if ((bottom - j) % 2 == 0)
					{
						for (int k = j; k >= 0; k--)
						{
							for (int m = 0; m < levelnum[k]; m++)
							{
								tower[cur].pop_back();
								tower[target].push_back(k + 1);
							}
						}
						tmp = target;
						target = non;
						non = cur;
						cur = tmp;
						bottom = j;
					}
					else
					{
						tmp = target;
						target = non;
						non = tmp;
						for (int k = j; k >= 0; k--)
						{
							for (int m = 0; m < levelnum[k]; m++)
							{
								tower[cur].pop_back();
								tower[target].push_back(k + 1);
							}
						}
						tmp = target;
						target = non;
						non = cur;
						cur = tmp;
						bottom = j;
					}
					if (l <= levelnum[j + 1])
					{
						for (int k = 0; k < l; k++)
						{
							tower[d].pop_back();
							tower[target].push_back(j + 2);
						}
						l = 0;
					}
					else
					{
						for (int k = 0; k < levelnum[j + 1]; k++)
						{
							tower[d].pop_back();
							tower[target].push_back(j + 2);
						}
						l = l - levelnum[j + 1];
					}
				}
			}
		}
		if (tower[1].size() == 0)
		{
			cout << 0 << endl;
		}
		else {
			for (int j = tower[1].size() - 1; j >= 0; j--)
			{
				cout << tower[1][j] << " ";
			}
			cout << endl;
		}
	}
}