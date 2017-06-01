#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct city {
	int car;
	int park;
	city(int car, int park) {
		this->car = car;
		this->park = park;
	}
};

struct road {
	int edge1;
	int edge2;
	road(int eg1, int eg2) {
		this->edge1 = eg1;
		this->edge2 = eg2;
	}
};

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;

		int sumpark = 0, sumcar = 0; //���� ���̽ü� ���� �ʱ�ȭ
		city* cityinfo[5000];
		queue<int> passq;
		queue<road*> rdq;
		road* temp;

		vector<int> roadlist[5000];

		long long int maxmove = 0, move;

		//�� ���� ���̽ü� ī��Ʈ �� �������� �Է�
		for (int i = 1; i <= N; i++)
		{
			int car, park;
			cin >> car >> park;
			sumcar += car;
			sumpark += park;
			cityinfo[i] = new city(car, park);
		}

		// �������� �Է�
		for (int i = 0; i < M; i++)
		{
			int from, to;
			cin >> from >> to;
			roadlist[from].push_back(to);
			roadlist[to].push_back(from);
			rdq.push(new road(from, to));
		}

		while (!rdq.empty()) {//���� ����Ʈ�� ������� �������� ��� ����

			bool visit[5000] = { 0, };
			long long int city1car = 0, city1park = 0, city2car = 0, city2park = 0;
			temp = rdq.front(); //���� temp�� ���� ť�� ù��° ���� �Ҵ�
			rdq.pop();//ù��° �� ������

			visit[temp->edge2] = true; //���� ť�� �ִ� ����� ���������� ��� �湮������ �ٲ۴�
			visit[temp->edge1] = true;

			passq.push(temp->edge1); //������ ���ø���Ʈ�� ����� ���� �߰�

			int now;
			while (!passq.empty()) {
				now = passq.front();
				passq.pop();
				city1car += cityinfo[now]->car;
				city1park += cityinfo[now]->park;

				int size;
				size = roadlist[now].size();
				for (int j = 0; j < size; j++) {
					if (!visit[roadlist[now][j]]) {
						visit[roadlist[now][j]] = true;
						passq.push(roadlist[now][j]);
					}
				}
			}
			//������� BFS�˰���

			city2car = sumcar - city1car;
			city2park = sumpark - city1park;

			move = (city1car*city2park) + (city2car*city1park);

			if (maxmove < move)
			{
				maxmove = move;
			}

		}
		cout << maxmove << endl;
	}
}