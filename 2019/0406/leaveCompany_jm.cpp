#include <iostream>
#include <algorithm>

using namespace std;

int sch[2][15]; // schedule;
int d[20];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> sch[0][i] >> sch[1][i];
	}
	for (int i = 0; i < n; i++) {
		d[i + sch[0][i]] = max(d[i] + sch[1][i], d[i + sch[0][i]]);
		d[i + 1] = max(d[i], d[i + 1]);
	}
	cout << d[n] << '\n';
	return 0;
}
