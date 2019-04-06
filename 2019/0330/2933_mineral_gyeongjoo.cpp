/////////////실패한 코드임

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;	//막대 던질 횟수
int R, C;	//동굴 크기
int cave[100][100];
bool isVisited[100][100];
vector<pair<int, int>> cluster;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool flag;	////////////////////확인
int max_index;
int max_x;
int max_y;
int down;

void initialization() {
	memset(isVisited, 0, sizeof(isVisited));
	flag = false;	//바닥에 붙어있는지 확인되면 true. 공중에 떠있으면 false.
	max_index = 0;
	max_x = 0;
	max_y = 0;
	down = 0;
	cluster.clear();
}

void check(int x, int y) {	//dfs 로 바닥과 붙어있는지 확인. 아니라면 떨어뜨려야함.
	
	isVisited[x][y] = true;

	if (x == R - 1) {
		flag = true;
		return;	//	확인할 좌표가 바닥에 붙어있는경우 flag 설정후 정상종료	///////// && y >= 0 && y < C
	}
	
	for (int k = 0; k < 4; k++) {	//상하좌우  방향으로 확인!
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (cave[nx][ny] == 1 && nx >= 0 && nx < R && ny >= 0 && ny < C && isVisited[nx][ny]==false) {
			cluster.push_back(make_pair(ny, nx));
			check(nx, ny);
			if (flag == true)	return;
		}
		else continue;
	}
	
	//다 돌고 왔는데도 종료가 안된경우! 떨어뜨리자. 
	//cluster vector에 들어있는 좌표중 가장 아래쪽 좌표 찾아내기

	sort(cluster.begin(), cluster.end());

	int size = cluster.size();

	max_x = cluster[size - 1].second; 
	max_y = cluster[size - 1].first;
	
	/////////////////////문제의 부분////////////////
	
	for (int i = max_y+1; i < R; i++) {
		if (cave[max_x][i] == 1 || i==R-1) {	//떨어뜨리다가 미네랄을 만남
			//모양 그대로 유지하면서 y좌표만 변형시키며 떨어뜨리기
			for (int k = size; k >0 ; k--) {
				cave[cluster[size - 1].second][cluster[size - 1].first + down] = 1;
				cave[cluster[size - 1].second][cluster[size - 1].first] = 0;
				cluster.pop_back();
				size = cluster.size();
			}
			//break;
			return;
		}
		else down++;
	}
	
	////////////////////////////////////
	
	
}


int main() {
	cin >> R >> C;

	memset(cave, 0, sizeof(cave));
	memset(isVisited, 0, sizeof(isVisited));	////////////////////////////////////확인해보기
	cluster.clear();

	for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {

		char tmp;
		cin >> tmp;
		if (tmp == 'x') {
			cave[i][j] = 1;	//x 면 1을 입력
		}

	}

	cin >> N;
	int direct=0;	//direct = 0 or EVEN : left to right , direct = ODD : right to left.

	for (int i = 0; i < N; i++) {

		int height;
		cin >> height;
		
		if (direct == 0 || direct % 2 == 0)//0 or EVEN : left to right
		{
			for (int j = 0; j < C; j++) {
				if (cave[R - height][j] == 1) {	//막대기 던져서 미네랄과 만나는 첫 부분
					cave[R - height][j] = 0;	//미네랄은 파괴되고

					//up check	(파괴된 미네랄의 위쪽을 검사)
					initialization();
					int nx = R - height + dx[0];
					int ny = j + dy[0];
					cluster.push_back(make_pair(ny, nx));
					if (cave[nx][ny] == 1 && nx >= 0 && nx < R && ny >= 0 && ny < C)
						check(nx, ny);

					//down check
					initialization();
					nx = R - height + dx[1];
					ny = j + dy[1];
					cluster.push_back(make_pair(ny, nx));
					if (cave[nx][ny] == 1 && nx >= 0 && nx < R && ny >= 0 && ny < C)
						check(nx, ny);

					//right check
					initialization();
					nx = R - height + dx[3];
					ny = R - height + dy[3];
					cluster.push_back(make_pair(ny, nx));
					if(cave[nx][ny] == 1 && nx >= 0 && nx < R && ny >= 0 && ny < C)
						check(nx, ny);

					break;
				}
				else continue;
			}
		}
		else //ODD : right to left
		{
			for (int j = C - 1; j >= 0; j--) {
				if (cave[R - height][j] == 1) {
					cave[R - height][j] = 0;

					//up check
					initialization();
					int nx = R - height + dx[0];
					int ny = j + dy[0];
					cluster.push_back(make_pair(ny, nx));
					if (cave[nx][ny] == 1 && nx >= 0 && nx < R && ny >= 0 && ny < C)
						check(nx, ny);

					//down check
					initialization();
					nx = R - height + dx[1];
					ny = j + dy[1];
					cluster.push_back(make_pair(ny, nx));
					if (cave[nx][ny] == 1 && nx >= 0 && nx < R && ny >= 0 && ny < C)
						check(nx, ny);

					//left check
					initialization();
					nx = R - height + dx[2];
					ny = R - height + dy[2];
					cluster.push_back(make_pair(ny, nx));
					if (cave[nx][ny] == 1 && nx >= 0 && nx < R && ny >= 0 && ny < C)
						check(nx, ny);

					break;
				}
				else continue;
			}
		}
		direct += 1;
		
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (cave[i][j] == 1)	cout << "x";
			else cout << ".";
		}
		cout << '\n';
	}

}
