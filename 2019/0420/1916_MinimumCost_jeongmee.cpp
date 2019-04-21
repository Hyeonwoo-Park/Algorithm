#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, finish;
int fee[1001];
vector <pair<int,int>> graph[1001];

int go(int start) {

	queue<int> q;
	q.push(start);
	fee[start] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int nx, cost;
			nx = graph[x][i].first;
			cost = graph[x][i].second;
			if (fee[nx] == -1 || fee[x] + cost < fee[nx]) {
				fee[nx] = fee[x] + cost;
				if (nx != finish) {
					q.push(nx);
				}
			}
		}
	}
	return fee[finish];
}

int main() {

	memset(fee, -1, sizeof(fee));
	cin >> n >> m;

	while (m--) {
		int b, e, c; cin >> b >> e >> c;
		graph[b].push_back(make_pair(e, c));
	}

	int start; cin >> start >> finish;

	cout << go(start) << '\n';

	return 0;
}
