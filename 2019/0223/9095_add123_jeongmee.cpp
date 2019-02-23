#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;

	for (int testcase = 1; testcase <= t; testcase++) {

		int num = 0;
		cin >> num;

		int dp[12] = { 0, };
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= num; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		} 

		cout << dp[num] << endl;
	}

	return 0;
}
