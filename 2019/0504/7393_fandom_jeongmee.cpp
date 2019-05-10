#include <cstdio>
#include <cstring>
//내가 푼거 아님;;

const int mod = 1e9;
int n, ans, dp[101][10][1025];

int dfs(int len, int num, int msk) {

	int &ret = dp[len][num][msk];
	msk |= (1 << num);

	if (num < 0 || num > 9) return 0;
	if (len == n) return (msk == (1 << 10) - 1) ? 1 : 0;
	if (ret != -1) return ret;

	return ret = ((long long)dfs(len + 1, num - 1, msk) + dfs(len + 1, num + 1, msk)) % mod;
}


int main() {
	int t;
   	scanf("%d",&t);
    
   	for(int tc = 1; tc <=t;tc++){
      		ans = 0;
    		scanf("%d", &n);
	  	memset(dp, -1, sizeof(dp));
        
		for (int i = 1; i <= 9; i++)
         		ans = ((long long)ans + dfs(1, i, 0)) % mod;

		printf("#%d %d\n", tc, ans);
   }
	return 0;
}
