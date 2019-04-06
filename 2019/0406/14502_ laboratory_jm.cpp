#include <iostream>
#include <queue>

using namespace std;

int n, m;
int room[8][8];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

int bfs(queue<pair<int, int>> q) {
	
	int space = 0;
	int d[8][8] = { 0, };

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = room[i][j];

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (d[nx][ny] == 0)
			{
				d[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (d[i][j] == 0)
				space++;
		}
	}
	return space;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;
	queue<pair<int, int>> q;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}
	for (int i1 = 0; i1 < n; i1++)
	{
		for (int j1 = 0; j1 < m; j1++)
		{
			if (room[i1][j1] != 0) continue;
			for (int i2 = 0; i2 < n; i2++)
			{
				for (int j2 = 0; j2 < m; j2++)
				{
					if (room[i2][j2] != 0) continue;
					for (int i3 = 0; i3 < n; i3++)
					{
						for (int j3 = 0; j3 < m; j3++)
						{
							if (room[i3][j3] != 0) continue;
							if (i1 == i2 && j1 == j2)
								continue;
							if (i2 == i3 && j2 == j3)
								continue;
							if (i1 == i3 && j1 == j3)
								continue;

							room[i1][j1] = 1;
							room[i2][j2] = 1;
							room[i3][j3] = 1;

							int x = bfs(q);
							if (x > ans)
								ans = x;

							room[i1][j1] = 0;
							room[i2][j2] = 0;
							room[i3][j3] = 0;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
