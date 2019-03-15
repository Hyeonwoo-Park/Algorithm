#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100000 + 1;

int v;
bool isVisit[MAX] = { false, };
vector <pair<int, int>> d[MAX];

int maximum = 0;
int farN = 0;

void dfs(int node, int distance) {

	if (isVisit[node])
		return;

	isVisit[node] = true;

	if (maximum < distance)
	{
		maximum = distance;
		farN = node;
	}

	for (int i = 0; i < d[node].size(); i++)
		dfs(d[node][i].first, distance + d[node][i].second);
	
	return;
}
int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> v;

	for (int i = 0; i < v; i++)
	{
		int n1;
		cin >> n1;
		while (1)
		{
			int n2, dist;
			cin >> n2;
			if (n2 == -1)
				break;
			cin >> dist;
			d[n1].push_back({ n2, dist });
		}
	}
	//막혔던 부분 : 한 번만 dfs를 해서 찾을 수 없음.
	//root node가 1이라고 가정했을 때, 가장 멀리 있는 node를 찾아야 함.
	dfs(1, 0);
	//가장 멀리 있는 node에서 가장 멀리 있는 node까지.
	memset(isVisit, false, sizeof(isVisit));
	maximum = 0;
	dfs(farN, 0);

	cout << maximum << '\n';
	return 0;
}
