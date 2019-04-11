#include <iostream>
#include <algorithm>

using namespace std;

int N;
int t[16];
int p[16];
int d[16];


int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t[i];
		cin >> p[i];
		d[i] = p[i];
	}


	int ans=0;

	for (int i = 1; i <= N; i++) {
		if (i + t[i] <= N + 1) ans = max(ans, d[i]);
	}

	cout << ans << '\n';

	return 0;
}
