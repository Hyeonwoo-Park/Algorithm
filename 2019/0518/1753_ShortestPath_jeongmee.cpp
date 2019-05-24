#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

const int MAX = 999999;

int ans;
bool check[20001];
int road[20001];
vector <pair<int, int>> g[20001];

void bfs(int a) {

	memset(check, false, sizeof(check));
	memset(road, MAX, sizeof(road));
	priority_queue <pair<int, int>, vector< pair<int,int> >, greater< pair<int, int> > > q;
	q.emplace(0, a);
	road[a] = 0;
	check[a] = true;

	while (!q.empty()) {
		pair<int, int> x;
		x = q.top();
		q.pop();

		for (int i = 0; i < g[x.second].size(); i++) {
			if (check[g[x.second][i].first] == false || road[g[x.second][i].first] > x.first + g[x.second][i].second)
			{
				check[g[x.second][i].first] = true;
				road[g[x.second][i].first] = x.first + g[x.second][i].second;
				q.emplace(x.first + g[x.second][i].second, g[x.second][i].first);
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, e, s;
	cin >> n >> e >> s;

	for (int i = 1; i <= e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
	}

	bfs(s);

	for (int k = 1; k <= n; k++) {
		
		if (!check[k])
			cout << "INF\n";
		else
			cout << road[k] << '\n';
	}

	return 0;
}
