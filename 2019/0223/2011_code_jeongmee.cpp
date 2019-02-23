#include <iostream>
#include <cstring>
using namespace std;

#define mod 1000000

int main() {

	ios::sync_with_stdio(false); cin.tie(0);

	char code[5001];
	int dp[5001] = { 0, };
	dp[0] = 1;
	cin >> code+1;
	int endP = strlen(code + 1);

	for (int i = 1; i <= endP; i++) {

		int x = code[i] - '0';
		if (x >= 1 && x <= 9)
		{
			dp[i] = dp[i - 1] % mod;
		}
		if (i == 1) continue;

		x = (code[i - 1] - '0') * 10 + (code[i] - '0');
		if (x >= 10 && x <= 26)
		{
			dp[i] = (dp[i] + dp[i - 2]) % mod;
		}
	}
	cout << dp[endP] << endl;

	return 0;
}
