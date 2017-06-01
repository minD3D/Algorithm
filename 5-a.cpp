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
		cin >> N >> M; //인구수와 간선수 입력

		vector<city*> cap(N + 1); //도시의 번호와 매칭할 cap 벡터배열을 만든다

		for (int i = 1; i <= N; i++)//인구를 순서대로 입력
		{
			int population; //인구수를 입력받으며 city class인 object를 cap배열에 넣는다.
			cin >> population;
			cap[i] = new city(population);
			cap[i]->incidentCities.reserve(N + 1); //cap배열을 벡터크기를 N+1로 바꾼값으로 연결
		}

		//간선정의
		for (int i = 0; i < M; i++)//cap의 포인터가 서로를 가르키도록 한다
		{
			int d1, d2;
			cin >> d1 >> d2;
			cap[d1]->incidentCities.push_back(d2);
			cap[d2]->incidentCities.push_back(d1);
		}

		vector<int> x(N + 1); //각 도시번호와 xi 공식값을 매칭하기위한 백터

		for (int i = 1; i <= N; i++) //너비우선탐색 알고리즘
		{
			queue<int> que; 
			int s = 0;
			que.push(i);
			int cnt = 1;//distance값
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

			x[i] = (N - 1)*(cnt-1) + s;//xi의 공식

			for (int j = 1; j <= N; j++) {
				cap[j]->visited = false; //다시 탐색을 위해 visited값 초기화
			}
		}

		int min = 999999999;
		int minA = 0;
		for (int i = 1; i <= N; i++) //최소인 xi 값과 그 값과 같은 도시가 있을시 인구수 확인
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