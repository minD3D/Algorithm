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

		int sumpark = 0, sumcar = 0; //차와 놀이시설 총합 초기화
		city* cityinfo[5000];
		queue<int> passq;
		queue<road*> rdq;
		road* temp;

		vector<int> roadlist[5000];

		long long int maxmove = 0, move;

		//총 차와 놀이시설 카운트 및 도시정보 입력
		for (int i = 1; i <= N; i++)
		{
			int car, park;
			cin >> car >> park;
			sumcar += car;
			sumpark += park;
			cityinfo[i] = new city(car, park);
		}

		// 도로정보 입력
		for (int i = 0; i < M; i++)
		{
			int from, to;
			cin >> from >> to;
			roadlist[from].push_back(to);
			roadlist[to].push_back(from);
			rdq.push(new road(from, to));
		}

		while (!rdq.empty()) {//도로 리스트가 비어있지 않은동안 계속 수행

			bool visit[5000] = { 0, };
			long long int city1car = 0, city1park = 0, city2car = 0, city2park = 0;
			temp = rdq.front(); //임의 temp에 도로 큐의 첫번째 값을 할당
			rdq.pop();//첫번째 값 날리기

			visit[temp->edge2] = true; //도로 큐에 있는 연결된 도시정보를 모두 방문함으로 바꾼다
			visit[temp->edge1] = true;

			passq.push(temp->edge1); //지나간 도시리스트에 출발점 도시 추가

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
			//여기까지 BFS알고리즘

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