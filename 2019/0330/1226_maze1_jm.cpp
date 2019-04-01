#include <cstdio>
#include <queue>

using namespace std;

int ans;
int map[16][16];
bool isVisit[16][16];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void bfs(int a, int b)
{
	queue <pair<int, int>> q;
	q.push(make_pair(a, b));
	isVisit[a][b] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 16 && ny < 16)
			{
				//도착점이라면 ans = 1로 하고, 리턴
				if (map[nx][ny] == 3)
				{
					ans = 1;
					return;
				}
				//방문한 적 없는 길인 경우
				else if (map[nx][ny] == 0 && isVisit[nx][ny] == false)
				{
					isVisit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {

	for (int tc = 1; tc <= 10; tc++)
	{
		scanf("%d", &tc);
		ans = 0;
		int x = 0, y = 0; //starting point;
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				scanf("%1d", &map[i][j]);

				if (map[i][j] == 1)
					isVisit[i][j] = true;

				else if (map[i][j] == 2)
				{
					x = i;
					y = j;
					isVisit[i][j] = false;
				}

				else
					isVisit[i][j] = false;
			}
		}

		bfs(x, y);

		printf("#%d %d\n", tc, ans);
	}

	return 0;
}
