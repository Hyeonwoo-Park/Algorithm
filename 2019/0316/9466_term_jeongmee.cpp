#include <iostream>
#include <algorithm>

using namespace std;
//team에 중복으로 소속되는 학생은 없음. 단방향 linked list에서 loop찾기 문제.
int n, cnt;
int d[100001];
bool ed[100001];
bool isVisit[100001];

void dfs(int now) {

	isVisit[now] = true;

	if (isVisit[d[now]] == false)
		dfs(d[now]);

	else if (ed[d[now]] == false)
	{
		for (int i = d[now]; i != now; i = d[i])
			cnt++;
		cnt++;
	}

	ed[now] = true;

	return;
}

int main() {

	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {

		cin >> n;
		cnt = 0;
		fill(ed, ed + n + 1, false);
		fill(isVisit, isVisit + n + 1, false);

		for (int i = 1; i <= n; i++)
		{
			cin >> d[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (isVisit[i] == false)
			{
				dfs(i); // now
			}
		}
		
		cout << n - cnt << '\n';
	}

	return 0;
}
