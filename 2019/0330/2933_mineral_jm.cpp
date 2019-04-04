#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
char a[111][111];
int c[111][111];
int n, m;
vector<pair<int, int>> group;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void dfs(int x, int y) {
	
	if (a[x][y] == '.') return;
	
	if (c[x][y]) return;
	
	c[x][y] = true;

	group.emplace_back(x, y);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			dfs(nx, ny);
		}
	}
}

void simulate() {
	memset(c, false, sizeof(c));
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
		
			if (a[x][y] == '.') continue;
			if (c[x][y]) continue;
			group.clear();
			dfs(x, y);
			//이 그룹이 떨어져야 하는지 아닌지 판별

			vector<int> low(m, -1);
			for (auto &p : group) {
				low[p.second] = max(low[p.second], p.first);
				a[p.first][p.second] = '.';
			}
			int lowest = n;
			for (int i, j = 0; j < m; j++) {
				if (low[j] == -1) continue;
				for (i = low[j]; i < n && a[i][j] == '.'; i++);
				lowest = min(lowest, i - low[j] - 1); //간격 중에 가장 작은 간격을 찾아서
			}

			for (auto &p : group) {
				p.first += lowest; // 내려준다.
				a[p.first][p.second] = 'x';
				c[p.first][p.second] = true;
			}
		} 
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int height;
		cin >> height;
		height = n - height;
		if (i % 2 == 0) {
			for (int j = 0; j < m; j++) {
				if (a[height][j] == 'x') {
					a[height][j] = '.';
					break;
				}
			}
		}
		else {
			for (int j = m - 1; j >= 0; j--) {
				if (a[height][j] == 'x') {
					a[height][j] = '.';
					break;
				}
			}
		}
		simulate();
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
	return 0;
}
