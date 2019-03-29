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

///////////////원래 하려고 했던 방식

/*
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;	//테스트 갯수
int N;	//점프대의 수. N<=10000
int H[10000];	//N개의 점프대 각각의 높이. H[i]s는 1이상 100000 이하.
int d[10001];	//d[N] 에는 d[1]부터 d[N-1]까지 N-1개의 H가 최적화되어 정렬되어 있으며, H[N]을 추가하여 d[N+1]로 만들거임.
int gap[10001];	//gap[k]에는 d[k]와 d[k+1]의 절댓값 차이가 저장되어 있음. 


int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		memset(H, 0, sizeof(H));
		memset(gap, 0, sizeof(gap));

		H[0] = 0;
		for (int i = 1; i <= N; i++) {
			cin >> H[i];
		}

		sort(H, H + N + 1);	//입력받은 H를 오름차순으로 정렬

		//초기화
		d[0] = 0;	//사용 X
		d[1] = H[1];
		d[2] = H[2];
		d[3] = H[3];

		//H[4] 부터 H[N] 까지 d에 넣을 자리를 찾을거야.
		for (int j = 3; j <= N - 1; j++) {

			//H가 d[i] 중에 같은 수가있으면 그 수의 오른쪽에 넣자.
			int flag = 0;
			for (int i = 1; i <= j; i++) {
				if (d[i] == H[j + 1]) {
					for (int k = j; k >= i; k--) {
						d[k + 1] = d[k];
					}
					d[i + 1] = H[j + 1];
					flag = 1;
					break;
				}
			}
			if (flag == 1) continue;

			//H가 d[i] d[i+1] 사이에 들어간다고 가정. 그 차이 중 큰값을 기록.
			for (int i = 1; i < j; i++) {
				gap[i] = max(abs(d[i] - H[j + 1]), abs(d[i + 1] - H[j + 1]));
			}
			gap[j] = max(abs(d[j] - H[j + 1]), abs(d[1] - H[j + 1]));

			//gap 중에 젤 작은 값 찾자. 그래야 어디에 들어갈지 결정할 수 있어.
			int min = 200000;	////////long 써야하나?
			int min_index = 0;
			for (int i = 1; i <= j; i++) {
				if (gap[i] < min) {
					min = gap[i];
					min_index = i;
				}
			}

			//H[j+1]은 그럼 d[min_index+1] 자리에 들어가야겠네.
			//d[min_index+1]부터 d[]까지 자리를 한칸씩 옮겨서 확보하자.
			for (int i = j; i >= min_index + 1; i--) {
				d[i + 1] = d[i];
			}
			d[min_index + 1] = H[j + 1];

		}
		
		for (int i = 1; i <= N; i++) {
			cout << d[i] << ' ';
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
*/
