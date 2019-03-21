#include <iostream>
#include <queue>
using namespace std;

int d[1001][1001];
int noRipe;
int dm[] = { 0, -1, 0, 1 };
int dn[] = { 1, 0, -1, 0 };

queue<pair<int, int>> q;

int main() {

	int m, n;
	cin >> m >> n;
	int allTomato = 0;
	noRipe = 0;
	// 0 = 안 익은 토마토, 1 = 익은 토마토, -1 = 빈 칸
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> d[i][j];
			if (d[i][j] == 0)
			{
				allTomato = 1;
				noRipe += 1;
			}
			if (d[i][j] == 1)
				q.push(make_pair(i, j));
		}
	if (allTomato == 0)
		cout << "0\n";
	else {
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dn[i];
				int ny = y + dm[i];
				if(nx >= 0 && nx < n && ny >= 0 && ny < m)
					if (d[nx][ny] == 0)
					{
						d[nx][ny] = d[x][y] + 1;
						noRipe -= 1;
						q.push(make_pair(nx, ny));
					}
			}
		}
		if (noRipe != 0)
			cout << "-1\n";
		else
		{
			int maxVal = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					if (d[i][j] > maxVal)
						maxVal = d[i][j];
				}
			cout << maxVal-1 << '\n';
		}
	}

	return 0;
}
