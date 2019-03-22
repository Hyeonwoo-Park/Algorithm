#include <iostream>
#include <cstring> //memset ������
using namespace std;

int a[100001];
bool check[100001];
bool done[100001]; //Ȯ��!

int cnt;
int n;

void dfs(int x) {
	check[x] = true; //�湮�ߴٰ� ǥ��
	
	int next = a[x];

	if (check[next] == false) { // ������� �湮 ���߿�
		dfs(next);
	}

	else {
		if (done[next] == false) {// ������� �湮�� �ߴµ� Ȯ���� ���� -> cycle�̾�
			for (int i = next; i != x; i = a[i])
				cnt++; //cylce�� ����ִ��� ����
			cnt++; //�ڱ⵵ ����
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