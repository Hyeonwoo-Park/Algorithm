#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;	//테스트 갯수
int N;	//점프대의 수. N<=10000
int H[10000];	//N개의 점프대 각각의 높이. H[i]s는 1이상 100000 이하.
int d[10001];	//d[N] 에는 d[1]부터 d[N-1]까지 N-1개의 H가 최적화되어 정렬되어 있으며, H[N]을 추가하여 d[N+1]로 만들거임.
	

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> N;
		memset(H, 0, sizeof(H));

		for (int i = 1; i <= N; i++) {
			cin >> H[i];
		}

		sort(H, H + N + 1);	//입력받은 H를 오름차순으로 정렬

		int k = 1;
		for (int i = 1; i <= N; i += 2) {
			d[k] = H[i];
			k++;
		}

		if (N % 2 == 0) {	//N이 짝수
			for (int i = N; i >= 2; i -= 2) {
				d[k] = H[i];
				k++;
			}
		}
		else {	//N이 홀수
			for (int i = N - 1; i >= 2; i -= 2) {
				d[k] = H[i];
				k++;
			}
		}

		/*
		for (int i = 1; i <= N; i++) {
			cout << d[i] << ' ';
		}
		*/

		int ans = 0;
		for (int i = 1; i <= N - 1; i++) {
			if (abs(d[i] - d[i + 1]) > ans)
				ans = abs(d[i] - d[i + 1]);
		}

		if (abs(d[N] - d[1]) > ans)	ans = abs(d[N] - d[1]);

		cout << '#' << t << ' ' << ans << '\n';

	}

	return 0;
}
