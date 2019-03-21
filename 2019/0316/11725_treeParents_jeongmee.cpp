#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000 + 1;

vector<int> p(MAX);
vector<int> v[MAX];

void findParents(int now) {

	for (int i = 0; i < v[now].size(); i++)
	{
		if (v[now][i] != p[now]) // vector 안에 저장된 값이 부모노드가 아니라면 자식노드
		{
			p[v[now][i]] = now;
			findParents(v[now][i]);
		}
	}
	return ;
}

int main() {

	int n;
	cin >> n; // 2 <= n <= 100000

	int dn = n - 1;
	while (dn--)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	p[1] = 0;
	findParents(1);

	for (int i = 2; i <= n ; i++)
		cout << p[i] << '\n';

	return 0;
}
