#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define INF 10001;

struct Graph {
	vector<pair<int, int> > adjacent[10000];
	bool *nodeVisited;
	int *dist;
};

void Dijkstra(struct Graph graph, int N);
int sum = 0;

int main() {
	int T, N, M, i;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		struct Graph graph;
		graph.nodeVisited = new bool[N];
		graph.dist = new int[N];
		for (i = 0; i < N; i++) {
			graph.nodeVisited[i] = false;
			graph.dist[i] = INF;
		}

		int n1, n2, e;
		for (i = 0; i<M; i++) {
			cin >> n1 >> n2 >> e;
			graph.adjacent[n1].push_back(make_pair(n2, e));
			graph.adjacent[n2].push_back(make_pair(n1, e));
		}

		Dijkstra(graph, N);
		sum = 0;
		delete graph.nodeVisited;
		delete graph.dist;
	}
	return 0;
}

void Dijkstra(struct Graph graph, int N) {
	priority_queue <pair<int, int> > pq;
	graph.dist[0] = 0;
	pq.push(make_pair(0, 0));
	int i;
	while (!pq.empty()) {
		int d = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		graph.nodeVisited[v] = true;
		if (graph.dist[v] != d)
			continue;
		for (i = 0; i<(signed)graph.adjacent[v].size(); i++) {
			int there = graph.adjacent[v][i].first;
			int nextDist = graph.adjacent[v][i].second;

			if (graph.nodeVisited[v] == true && graph.nodeVisited[there] == false
				&& graph.dist[there] > nextDist) {
				graph.dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}

	for (i = 0; i<N; i++) {
		sum += graph.dist[i];
	}
	cout << sum << endl;
}
