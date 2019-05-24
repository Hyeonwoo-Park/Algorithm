//메모리 초과...

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int ans;
bool check[100001];
vector < pair<int, int> > v[100001];

void bfs(int a, int b) {

	memset(check, false, sizeof(check));
	queue <pair<int, int>> q;
	q.emplace(a, 0);
	check[a] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int x_sum = q.front().second;
		q.pop();

		if (x == b) {
			ans = x_sum;
			break;
		}

		for (int i = 0; i < v[x].size(); i++) {
			if(!check[v[x][i].first])
				q.emplace(v[x][i].first, x_sum + v[x][i].second);
		}
	}
}

int main() {

	while (true) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		for (int i = 1; i <= n; i++)
			v[i].clear();
		
		while (m--) {
			int a, b;
			char c;
			cin >> c >> a >> b;

			if (c == '?') {
				ans = 9999999;
				bfs(a, b);

				if (ans == 9999999)
					cout << "UNKNOWN\n";
				else
					cout << ans << '\n';
			}
			else if(c == '!') {
				int d;
				cin >> d;

				v[a].emplace_back(b, d);
				v[b].emplace_back(a, -d);
			}
		}
	}

	return 0;
}
