#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;

	while (t--) {
		//모든 짧은 시간 중에 제일 긴 시간이 min 모든 긴 시간 중에 제일 긴 시간이 max!
		int l, n, x;
		cin >> l >> n;
		int mn = -1, mx = -1;

		while (n--) {	
			cin >> x;
			int max_x = (l - x) > x ? l - x : x;
			int min_x = (l - x) < x ? l - x : x;
			if (mx == -1 || mx < max_x) mx = max_x;
			if (mn == -1 || mn < min_x) mn = min_x;
		}
		cout << mn << ' ' << mx << '\n';
	}
	return 0;
}
