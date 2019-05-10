#include <cstdio>
#include <cstring>

const int mod = 1e9;
int n, ans, dp[101][10][1025];
//숫자가 사용됨 사용되지 않음을 비트로 표현. bitmask dp.

int dfs(int len, int num, int msk) {

	int &ret = dp[len][num][msk];
	msk |= (1 << num); //msk = msk||(1<<num); 원래 msk에 표시된 bit에서 내가 1로 만들고 싶은 비트도 1로 만들어줌!

	if (num < 0 || num > 9) return 0;
	if (len == n) return (msk == (1 << 10) - 1) ? 1 : 0; //mak == 1111111111(2) ? 1 : 0;
	if (ret != -1) return ret; // 값이 이미 있다.

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
