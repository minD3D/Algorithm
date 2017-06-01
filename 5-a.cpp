#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class city {
public:
	city(int pop)
	{
		population = pop;
		visited = false;
	}

public:
	vector<int> incidentCities;
	int population;
	bool visited;
};


int main() {
	ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
	int N, M;
	for(int i=0; i<T; i++){
		cin >> N >> M; //�α����� ������ �Է�

		vector<city*> cap(N + 1); //������ ��ȣ�� ��Ī�� cap ���͹迭�� �����

		for (int i = 1; i <= N; i++)//�α��� ������� �Է�
		{
			int population; //�α����� �Է¹����� city class�� object�� cap�迭�� �ִ´�.
			cin >> population;
			cap[i] = new city(population);
			cap[i]->incidentCities.reserve(N + 1); //cap�迭�� ����ũ�⸦ N+1�� �ٲ۰����� ����
		}

		//��������
		for (int i = 0; i < M; i++)//cap�� �����Ͱ� ���θ� ����Ű���� �Ѵ�
		{
			int d1, d2;
			cin >> d1 >> d2;
			cap[d1]->incidentCities.push_back(d2);
			cap[d2]->incidentCities.push_back(d1);
		}

		vector<int> x(N + 1); //�� ���ù�ȣ�� xi ���İ��� ��Ī�ϱ����� ����

		for (int i = 1; i <= N; i++) //�ʺ�켱Ž�� �˰���
		{
			queue<int> que; 
			int s = 0;
			que.push(i);
			int cnt = 1;//distance��
			int beforeSize = 1;
			cap[i]->visited = true;
			while (que.empty() == false)
			{
				for (int j = 0; j < beforeSize; j++)
				{
					int temp = que.front();
					for (int k = 0; k<(signed)(cap[temp]->incidentCities.size()); k++)
					{
						if (cap[cap[temp]->incidentCities[k]]->visited == false) {
							que.push(cap[temp]->incidentCities[k]);
							cap[cap[temp]->incidentCities[k]]->visited = true;
							s += cnt;
						}
					}
					que.pop();
				}
				beforeSize = que.size();
				cnt++;
			}

			x[i] = (N - 1)*(cnt-1) + s;//xi�� ����

			for (int j = 1; j <= N; j++) {
				cap[j]->visited = false; //�ٽ� Ž���� ���� visited�� �ʱ�ȭ
			}
		}

		int min = 999999999;
		int minA = 0;
		for (int i = 1; i <= N; i++) //�ּ��� xi ���� �� ���� ���� ���ð� ������ �α��� Ȯ��
		{
			if (min == x[i])
			{
				if ((cap[i]->population) > (cap[minA]->population)) {
					minA = i;
				}
			}
			else if (min > x[i])
			{
				min = x[i];
				minA = i;
			}

		}

		cout << minA << endl;
		for (int i = 1; i <= N; i++) {
			delete cap[i];
			cap[i] = nullptr;
		}
	}
	return 0;
}