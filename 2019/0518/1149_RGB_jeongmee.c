#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int R = 0, G = 1, B = 2;

int main(void) {

	int total_N[1000][4] = { 0 }, N;
	scanf("%d", &N);

	scanf("%d", &total_N[0][R]);
	scanf("%d", &total_N[0][G]);
	scanf("%d", &total_N[0][B]);

	total_N[0][3] = MIN(MIN(total_N[0][R], total_N[0][G]), MIN(total_N[0][B], total_N[0][G]));

	for (int i = 1; i < N; i++)
	{
		scanf("%d", &total_N[i][R]);
		scanf("%d", &total_N[i][G]);
		scanf("%d", &total_N[i][B]);

		total_N[i][R] += MIN(total_N[i - 1][G], total_N[i - 1][B]);
		total_N[i][G] += MIN(total_N[i - 1][R], total_N[i - 1][B]);
		total_N[i][B] += MIN(total_N[i - 1][R], total_N[i - 1][G]);

		total_N[i][3] = MIN(MIN(total_N[i][R], total_N[i][G]), MIN(total_N[i][B], total_N[i][G]));

	}

	printf("%d", total_N[N-1][3]);

}
