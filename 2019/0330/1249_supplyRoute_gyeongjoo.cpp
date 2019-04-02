#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int map[101][101];	//지도 배열
int route[101][101];	//최단거리 저장	
bool isVisited[101][101];	//방문 여부
int T;	//test case
int N;	//지도 크기
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> q;

int bfs(int a, int b) {
	isVisited[a][b] = true;

	q.push(make_pair(a, b));
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (isVisited[nx][ny]==false ) {
					isVisited[nx][ny] = true;
					route[nx][ny] = route[x][y] + map[nx][ny];
					q.push(make_pair(nx, ny));
				}
				else if (route[nx][ny] > route[x][y] + map[nx][ny]) {
					route[nx][ny] = route[x][y] + map[nx][ny];
					q.push(make_pair(nx, ny));
				}
				else continue;
			}
		}
	}

	return 0;

}

int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		memset(map, 0, sizeof(map));
		memset(route, 0, sizeof(route));


		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
			isVisited[i][j] = false;
		}

		bfs(0, 0);


		int ans = route[N-1][N-1];

		cout << '#' << t << " " << ans << '\n';
	}

	return 0;
}
