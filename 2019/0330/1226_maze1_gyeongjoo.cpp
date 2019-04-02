#include <iostream>
#include <queue>


int T; //testcase
int maze[16][16];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool isVisited[16][16];	

using namespace std;

int bfs(int a, int b) {
	queue<pair<int, int>> q;
	isVisited[a][b] = true;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < 16 && ny >= 0 && ny < 16 && isVisited[nx][ny] == false && (maze[nx][ny] == 0||maze[nx][ny]==3)) {
				if (maze[nx][ny] == 3) {
					return 1;
				}
				isVisited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}

	return 0;
	
}

int main() {

	for (int t = 1; t <= 10; t++) {

		cin >> T;

		for (int i = 0; i < 16; i++){
			for (int j = 0; j <16; j++) {
				
				scanf("%1d", &maze[i][j]);
				isVisited[i][j] = false;
			}
		}
		

		for (int i = 0; i <16; i++) {
			for (int j = 0; j <16; j++) {
				cout << maze[i][j] << " ";
			}
			cout << '\n';
		}


		//시작점 찾기
		int x = 0;
		int y = 0;
		for (int i = 0; i < 16; i++) for (int j = 0; j < 16; j++) {
			if (maze[i][j] == 2) {
				x = i;
				y = j;
				break;
			}
			else continue;
		}

		int ans;
	
		ans = bfs(x, y);

		cout << '#' << T << " " << ans << '\n';
	}

	return 0;
}
