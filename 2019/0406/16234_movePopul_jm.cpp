#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, l, r;
int map[50][50];
bool isVisit[50][50];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool simulation(int i, int j) {

	isVisit[i][j] = true;

	queue<pair<int, int>> q;
	queue<pair<int, int>> q_mem;

	int sum = 0;
	int num_coun = 0;
	sum += map[i][j];
	num_coun += 1;

	q.emplace(i, j);
	q_mem.emplace(i, j);

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {

			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (isVisit[nx][ny] == false) {

					int diff = map[x][y] - map[nx][ny];
					if (diff < 0) diff = -diff;

					if (diff >= l && diff <= r) {

						isVisit[nx][ny] = true;
						sum += map[nx][ny];
						num_coun += 1;

						q.emplace(nx, ny);
						q_mem.emplace(nx, ny);
					}
				}
			}
		}
	}

	if (num_coun > 1) { //인구 이동이 일어났음을 의미
		int ans = sum / num_coun;

		while (!q_mem.empty()) {

			int x = q_mem.front().first;
			int y = q_mem.front().second;
			q_mem.pop();

			map[x][y] = ans;
		}
		return true;
	}
	return false;
}



int main() {
	
	int ans = 0;
	cin >> n >> l >> r;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {

		memset(isVisit, false, sizeof(isVisit));
		bool isFin = true;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (isVisit[i][j] == false) {

					bool isMove = simulation(i, j);
					
					if (isMove) { //한 번이라도 인구 이동이 발생하면 while문 빠져나갈 수 없음.
						isFin = false;
					}
				}
			}
		}

		if (isFin) {
			break;
		}
		else {
			ans += 1;
		}
	}

	cout << ans << '\n';
	return 0;
}
