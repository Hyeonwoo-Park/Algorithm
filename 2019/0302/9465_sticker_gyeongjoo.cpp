#include "pch.h"
#include <iostream>
#define max(a,b) ((a)>(b)? (a):(b))

long long a[2][10001];	//[행][열]
long long d[10001][3];

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		//스티커 크기 결정 후 점수입력받기

		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)	cin >> a[0][i];	//위쪽
		for (int i = 1; i <= n; i++)	cin >> a[1][i]; //아래쪽

		//d[n][s] : 최대 점수 합. 2xn 스티커의 s번째 열의 스티커 상태 s . 
		//s=0 : 둘다 뜯지 않음	s=1 : 위에꺼 뜯음	s=2 : 아래꺼 뜯음
		
		d[0][0] = d[0][1] = d[0][2] = 0; //예외처리

		for (int i = 1; i <= n; i++) {
			d[i][0] = max(d[i - 1][0], max(d[i - 1][1], d[i - 1][2]));
			d[i][1] = max(d[i - 1][0], d[i - 1][2])+a[0][i];
			d[i][2] = max(d[i - 1][0], d[i - 1][1])+a[1][i];
		}

		long long ans = 0;
		
		ans = max(d[n][0], max(d[n][1], d[n][2]));

		cout <<"ans= "<< ans << '\n';
		

	}

	return 0;
}