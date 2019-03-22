#include <iostream>
#include <cstring> //memset 쓰려고
using namespace std;

int a[100001];
bool check[100001];
bool done[100001]; //확신!

int cnt;
int n;

void dfs(int x) {
	check[x] = true; //방문했다고 표시
	
	int next = a[x];

	if (check[next] == false) { // 다음노드 방문 안했오
		dfs(next);
	}

	else {
		if (done[next] == false) {// 다음노드 방문은 했는데 확신은 없어 -> cycle이야
			for (int i = next; i != x; i = a[i])
				cnt++; //cylce에 몇명있는지 세기
			cnt++; //자기도 포함
		}			
	}
	done[x] = true;
}

int main(void) {
	int T;
	cin >> T;
	while (T--) {
		memset(check, false, sizeof(check));
		memset(done, false, sizeof(done));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			check[i] = false;
			done[i] = false;
		}

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if(check[i]==false) dfs(i);
		}
		
		cout << n - cnt << '\n';
	}
	return 0;
}