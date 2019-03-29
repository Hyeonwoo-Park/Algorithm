#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;	//테스트 갯수
int N;	//점프대의 수. N<=10000
int H[10000];	//N개의 점프대 각각의 높이. H[i]s는 1이상 100000 이하.
int d[10001];	//초보자를 위한 점프 배치도
	

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> N;
		memset(H, 0, sizeof(H));

		for (int i = 1; i <= N; i++) {
			cin >> H[i];
		}

		sort(H, H + N + 1);	//입력받은 H를 오름차순으로 정렬
		
		//정렬된 H의 홀수번째 수 부터 오름차순으로 d에 채워넣고, 짝수번째 수는 내림차수로 d에 채워넣는다!

		int k = 1;
		//홀수번째수 채워넣기
		for (int i = 1; i <= N; i += 2) {
			d[k] = H[i];
			k++;
		}
		//짝수번째수 채워넣기
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
