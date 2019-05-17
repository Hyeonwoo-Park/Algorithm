#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int map[101][101];
int cnt[101][101];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void bfs() {

	memset(cnt, 0, sizeof(cnt));
	queue< pair<int, int> > q;
	cnt[0][0] = 1;
	q.emplace(0, 0);

	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (!map[nx][ny]) continue;
			
			if (cnt[nx][ny] == 0) {
				q.emplace(nx, ny);
				cnt[nx][ny] = cnt[x][y] + 1;
			}
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();
	printf("%d\n", cnt[n - 1][m - 1]);
	return 0;
}
