#include<iostream>
#include<array>
using namespace std;
int N, M;//���θ���� ������

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		cin >> N >> M;

		array <int, 2500> arr;
		for (int m = 0; m < M; m++) {
			int garo;
			cin >> garo;
			arr[m] = garo;
		}
		int start, end;
		cin >> start >> end;

		//���������� ���������� �̵��ϴ� ��� �����
		int *pathEnd = new int[M];
		int pnt = end;
		for (int i = M - 1; i >= 0; i--) {
			if (pnt == arr[i]) {
				pnt = arr[i] + 1;
				pathEnd[i] = pnt;
			}
			else if (pnt == arr[i] + 1) {
				pnt = arr[i];
				pathEnd[i] = pnt;
			}
			else
				pathEnd[i] = pnt;
		}

		int *pathStart = new int[M];
		pnt = start;
		for (int i = 0; i < M; i++) {
			if (pnt == arr[i]) {
				pnt = arr[i] + 1;
				pathStart[i] = pnt;
			}
			else if (pnt == arr[i] + 1) {
				pnt = arr[i];
				pathStart[i] = pnt;
			}
			else
				pathStart[i] = pnt;
		}


		bool change = false;
		for (int i = 0; i < M; i++) {
			if (pathStart[i] + 1 == pathEnd[i] || pathStart[i] - 1 == pathEnd[i] || pathStart[i] == pathEnd[i])
				change = true;

		}
		if (change) cout << 1;
		else cout << 0;
	}
	return 0;
}