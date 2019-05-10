#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool isVisit[101];
vector<int> map[101];

int main() {

	int n, m, i, ans;
	cin >> n >> m;
	memset(isVisit, false, sizeof(isVisit));

	for (i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		map[x].push_back(y); map[y].push_back(x);
	}

	isVisit[1] = true;
	queue<int> q; q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (i = 0; i < map[x].size(); i++) {
			if (isVisit[map[x][i]]) continue;
			isVisit[map[x][i]] = true;
			q.push(map[x][i]);
		}
	}

	ans = 0;
	for (i = 2; i <= n; i++)
		if (isVisit[i]) ans++;

	cout << ans << '\n';

	return 0;
}
