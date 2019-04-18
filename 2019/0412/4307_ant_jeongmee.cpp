#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int l, n, x;
		cin >> l >> n;
		int mn = -1, mx = -1;
		while (n--) {	
			cin >> x;
			mn = max(mn, min(x, l-x));
			mx = max(mx, max(x, l-x));	 
		}
		cout << mn << ' ' << mx << '\n';
	}
	return 0;
}
