#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int a[21][21];
bool isVisit[21][21];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int check(int x, int y) {

	int cnt = 0;

	bool _get = true;
	queue <pair<int,int>> q;
	q.emplace(x, y);
	isVisit[x][y] = true;
	cnt++;

	while (!q.empty()) {
		
		int _x = q.front().first;
		int _y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = _x + dx[i];
			int ny = _y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (a[nx][ny] == 0) _get = false;
			if (a[nx][ny] == 2 && !isVisit[nx][ny]) {
				isVisit[nx][ny] = true;
				q.emplace(nx, ny);
				cnt++;
			}
		}
 	}

	if (_get) {
		return cnt;
	}
	else {
		return 0;
	}
}

int countBlack() {

	int cnt = 0;
	memset(isVisit, false, sizeof(isVisit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2 && !isVisit[i][j]) {
				cnt += check(i, j);
			}
		}
	}

	return cnt;
}

int main() {

	int ans = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i1 = 0; i1 < n; i1++) {
		for (int j1 = 0; j1 < m; j1++) {
			if (a[i1][j1] == 0) {
				a[i1][j1] = 1;

				for (int i2 = i1; i2 < n; i2++) {
					for (int j2 = 0; j2 < m; j2++) {
						if ((i1 == i2) && (j1 == j2)) continue;
						if (a[i2][j2] == 0) {
							a[i2][j2] = 1;

							int cnt = countBlack();
							if (ans == -1 || cnt > ans) {
								ans = cnt;
							}

							a[i2][j2] = 0;
						}
					}
				}
				a[i1][j1] = 0;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
