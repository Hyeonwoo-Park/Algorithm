//////교훈 : 배열을 사랑하자
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int tile[20][20];
bool flag[20][20];

void up(int N) {
	for (int j = 0; j < N; j++) for (int i = 0; i < N; i++) {
		int x = i; 
		int y = j; 
		int nx = x - 1;
		int ny = y;

		//case 1: 현재 타일이 0이면 할 수 있는게 없음
		if (tile[x][y] == 0) continue;

		//case 2: 부딪히는 타일이 0일때 한칸씩 위로 대거이동!
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && tile[nx][ny] == 0) {
			int tmp_x = nx;
			int tmp_y = ny;
			
			while (tmp_x < N - 1) {
				tile[tmp_x][tmp_y] = tile[tmp_x + 1][tmp_y];
				flag[tmp_x][tmp_y] = flag[tmp_x + 1][tmp_y];
				tmp_x += 1;
			}
			

			tile[N - 1][y] = 0; //마지막 요소를 0으로 채워주자

			i = 0; //이동한뒤 다시 첨부터 살펴볼거양
			continue;
		}
		//case 3: 부딪히는 타일값이랑 같을때! 그리고 바뀐적없는 타일일때
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && tile[nx][ny] == tile[x][y] && flag[nx][ny] == false && flag[x][y] == false) {
			tile[nx][ny] *= 2;
			flag[nx][ny] = true;
			tile[x][y] = 0;

			i = 0; //이동한뒤 다시 첨부터 살펴볼거양
			continue;
		}
		else continue; //case 4: 부딪히는 타일값이 0도 아니고 다를때. 또는 범위를 벗어날때. 또는 바뀐적이 있는 타일일때
	}
}

void down(int N) {
	
	for (int j = 0; j < N; j++) for (int i = N - 1; i >= 0; i--) {
		int x = i; 
		int y = j; 
		int nx = x + 1;
		int ny = y;

		//case 1: 현재 타일이 0이면 할 수 있는게 없음
		if (tile[x][y] == 0) continue;

		//case 2: 부딪히는 타일이 0일때 한칸씩 아래로 대거이동!
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && tile[nx][ny] == 0) {
			int tmp_x = nx;
			int tmp_y = ny;

			while (tmp_x > 0) {
				tile[tmp_x][tmp_y] = tile[tmp_x - 1][tmp_y];
				flag[tmp_x][tmp_y] = flag[tmp_x - 1][tmp_y];
				tmp_x -= 1;
			}

			tile[0][y] = 0; //마지막 요소를 0으로 채워주자

			i = N - 1; //이동한뒤 다시 살펴볼거양
			continue;
		}
		//case 3: 부딪히는 타일값이랑 같을때! 그리고 바뀐적없는 타일일때
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && tile[nx][ny] == tile[x][y] && flag[nx][ny] == false && flag[x][y] == false) {
			tile[nx][ny] *= 2;
			flag[nx][ny] = true;
			tile[x][y] = 0;

			i = N - 1; //이동한뒤 다시 살펴볼거양
			continue;
		}
		else continue; //case 4: 부딪히는 타일값이 0도 아니고 다를때. 또는 범위를 벗어날때. 또는 바뀐적이 있는 타일일때
	}
}
void left(int N) {
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		int x = i; 
		int y = j; 
		int nx = x;
		int ny = y - 1;

		//case 1: 현재 타일이 0이면 할 수 있는게 없음
		if (tile[x][y] == 0) continue;

		//case 2: 부딪히는 타일이 0일때 한칸씩 왼쪽으로 대거이동!
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && tile[nx][ny] == 0) {

			int tmp_x = nx;
			int tmp_y = ny;

			while (tmp_y < N - 1) {
				tile[tmp_x][tmp_y] = tile[tmp_x][tmp_y + 1];
				flag[tmp_x][tmp_y] = flag[tmp_x][tmp_y + 1];
				tmp_y += 1;
			}

			tile[x][N - 1] = 0; //마지막 요소를 0으로 채워주자

			j = 0; //이동한뒤 다시 살펴볼거양
			continue;
		}
		//case 3: 부딪히는 타일값이랑 같을때! 그리고 바뀐적없는 타일일때
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && tile[nx][ny] == tile[x][y] && flag[nx][ny] == false && flag[x][y] == false) {
			tile[nx][ny] *= 2;
			flag[nx][ny] = true;
			tile[x][y] = 0;

			j = 0; //이동한뒤 다시 살펴볼거양
			continue;
		}
		else continue; //case 4: 부딪히는 타일값이 0도 아니고 다를때. 또는 범위를 벗어날때. 또는 바뀐적이 있는 타일일때
	}
}
void right(int N) {
	for (int i = 0; i < N; i++) for (int j = N - 1; j >= 0; j--) {
		int x = i; 
		int y = j; 
		int nx = x;
		int ny = y + 1;

		//case 1: 현재 타일이 0이면 할 수 있는게 없음
		if (tile[x][y] == 0) continue;

		//case 2: 부딪히는 타일이 0일때 한칸씩 오른쪽으로 대거이동!
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && tile[nx][ny] == 0) {

			int tmp_x = nx;
			int tmp_y = ny;

			while (tmp_y > 0) {
				tile[tmp_x][tmp_y] = tile[tmp_x][tmp_y - 1];
				flag[tmp_x][tmp_y] = flag[tmp_x][tmp_y - 1];
				tmp_y -= 1;
			}

			tile[x][0] = 0; //마지막 요소를 0으로 채워주자

			j = N - 1; //이동한뒤 다시 살펴볼거양
			continue;
		}
		//case 3: 부딪히는 타일값이랑 같을때! 그리고 바뀐적없는 타일일때
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && tile[nx][ny] == tile[x][y] && flag[nx][ny] == false && flag[x][y] == false) {
			tile[nx][ny] *= 2;
			flag[nx][ny] = true;
			tile[x][y] = 0;

			j = N - 1; //이동한뒤 다시 살펴볼거양
			continue;
		}
		else continue; //case 4: 부딪히는 타일값이 0도 아니고 다를때. 또는 범위를 벗어날때. 또는 바뀐적이 있는 타일일때
	}
}

int main(int argc, const char * argv[]) {
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++) {
		int N;
		string S;

		cin >> N >> S;

		//초기화
		memset(tile, 0, sizeof(tile));
	

		//타일 입력받기
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			cin >> tile[i][j];
			flag[i][j] = false;
		}

		if (S == "up")    up(N);
		else if (S == "down")  down(N);
		else if (S == "left")  left(N);
		else right(N);


		cout << '#' << k << '\n';

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << tile[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;

}
