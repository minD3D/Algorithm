#include<iostream>
#include <map>
using namespace std;
struct finger {
	int x;
	int y;
	finger(int a, int b)
	{
		this->x = a;
		this->y = b;
	}
	finger()
	{

	}
};
int main()
{
	std::ios::sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	bool check1 = false;
	for (int i = 0; i < testcase; i++)
	{
		bool jido[1010][1010] = { 0, };
		map<int, int> jm;
		map<int, int> jm2;
		map<int, int>::iterator iter, iter2;
		map<int, int> arr;
		
		
		int n, m, x, y;
		int a, b, c, d;
		int e, f;
		int q;
		int minx = 1000;
		int miny = 1000;
		check1 = false;
		int cnt = 0;
		cin >> n;
		//	bool com = true;
		q = 0;
		for (int i = 0; i < n; i++)			//등록지문 bool 이차원배열에 넣음
		{
			cin >> x >> y;
			
			if (x <= minx && y <= miny) {
			minx = x; miny = y;
			}
			
			jido[x][y] = true;
			jm2.insert(pair<int, int>(x * 10000 + y, true));
		}
		cin >> m;
		for (int j = 0; j < m; j++)			//비교지문 map에 넣음
		{
			cin >> x >> y;
			jm.insert(pair<int, int>(x * 10000 + y, true));
		}
		iter2 = jm2.begin();

		while(!check1 && (q != 9))
		{
			finger* arr2[100] = { 0, };		//초기화
			cnt = 0;
			int result[100] = { 0, };
			q++;

			minx = iter2->first / 10000;
			miny = iter2->first % 10000;
			
		for (iter = jm.begin(); iter != jm.end(); iter++)			//차이를 구함
		{
			//if (cnt >=(n*0.1)) break;
				if (cnt==9)break;
			//	arr.insert(pair<int, int>((minx * 10000 + miny) - (((iter->first / 10000) * 10000) + iter->first % 10000), true));
			e = minx - (iter->first / 10000);
			f = miny - (iter->first % 10000);
			arr2[cnt] = new finger(e, f);

			cnt++;
		}

		for (int i = 0; i <cnt; i++)	//비교지문과 차이값이 등록지문2차원배열에 있는지 확인
		{
			c = arr2[i]->x;
			d = arr2[i]->y;
			if (check1) break;
			for (iter = jm.begin(); iter != jm.end(); iter++)
			{/*
			 if ((iter->first / 10000) + (iter2->first / 10000) > 1000 || (iter->first % 10000) + (iter2->first % 10000) > 1000) continue;
			 if ((iter->first / 10000) + (iter2->first / 10000) < 0 || (iter->first % 10000) + (iter2->first % 10000) < 0) continue;
			 if(jido[(iter->first/10000) + (iter2->first/10000)][(iter->first%10000)+(iter2->first%10000)] == true)
			 result[i]++;
			 */
				a = iter->first / 10000;
				b = iter->first % 10000;

				if (a + c > 1000)continue;
				if (a + c < 0) continue;
				if (b + d > 1000)continue;
				if (b + d < 0)continue;
				if (jido[a + c][b + d]) { result[i]++; }
				//cout << "지도[" << a + c << "][" << b + d << "]가 등록되어있음"<<endl;}
			}


			if (((100 * result[i]) / n) >= 90)
			{
				check1 = true;
				break;
			}
			//q++;
		}
		iter2++;
		}
		
		if (check1)
			cout << true << endl;
		else
			cout << false << endl;
			
		}
		return 0;
	}