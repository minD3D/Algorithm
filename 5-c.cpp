#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N, M;
	int pdi;
	int num;

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vector<int> singerlist;
		bool x = 0;
		bool arr[1000][1000];

		cin >> N >> M;
		vector<int> index;
		index.resize(N);

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				arr[j][k] = 0;

		for (int j = 0; j < M; j++)
		{
			cin >> num;
			for (int k = 0; k < num; k++)
			{
				cin >> pdi;
				singerlist.push_back(pdi - 1);
			}

			for (int k = 0; k < (signed)singerlist.size() - 1; k++)
			{
				arr[singerlist[k]][singerlist[k + 1]] = 1;
			}
			while (!singerlist.empty())
			{
				singerlist.pop_back();
			}
		}

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (arr[j][k] == 1) index[k]++;

		for (int z = 0; z == 0;)
		{
			x = 0;
			for (int j = 0; j < N; j++) {
				if (index[j] == 0) {
					x = 1;
					index[j] = -1;
					singerlist.push_back(j);
					for (int k = 0; k < N; k++)
					{
						if (arr[j][k] == 1)
						{
							index[k] = index[k] - 1;
							arr[j][k] = 0;
						}
					}
					break;
				}
			}
			if (x == 0) break;
		}

		if ((signed)singerlist.size() < N) {
			cout << 0;
		}
		else {
			for (int j = 0; j < (signed)singerlist.size(); j++)
			{
				cout << singerlist[j] + 1 << " ";
			}
		}
		cout << endl;
	}
}
