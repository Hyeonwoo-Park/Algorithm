#include<cstdio>
#include<algorithm>
#define dis(a,b) sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]))
using namespace std;
int t, n, x[512], y[512];
double dp[512][512];
double f(int l, int r) {
	if (r == n - 1) return dis(l, r);
	if (dp[l][r]) return dp[l][r];
	return dp[l][r] = min(f(l, r + 1) + dis(r, r + 1), f(r, r + 1) + dis(l, r + 1));
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
		fill(&dp[0][0], &dp[511][512], 0);
		printf("%lf\n", f(0, 0));
	}
	return 0;
}
