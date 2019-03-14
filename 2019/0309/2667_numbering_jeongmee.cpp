#include <iostream>
#include <algorithm>
using namespace std;
int n, num; // num : 현재 단지 번호
int d[26][26] = { 0, };
int isVisit[26][26] = { 0, };
int home[169] = { 0, };//25인 경우 13*13이 최대 단지 수.
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void go(int x, int y) {
	//방문한 곳은 재방문하지 않는다. , 지도 안에 들어와야 한다.
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (isVisit[nx][ny] == 0 && d[nx][ny] == 1 && nx > 0 && nx <= n && ny > 0 && ny <= n)
		{
			isVisit[nx][ny] = 1;
			home[num] += 1;
			go(nx, ny);
		}
	}

	return;
}
int main() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%1d", &d[i][j]);

	num = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] == 1 && isVisit[i][j] == 0)
			{
				isVisit[i][j] = 1;
				num += 1;
				home[num] += 1;
				go(i, j);
			}
		}

	cout << num << endl;
	sort(home, home + num);
	for (int i = 1; i <= num; i++)
		cout << home[i] << endl;

	return 0;
}
