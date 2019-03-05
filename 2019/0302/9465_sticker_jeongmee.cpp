#include<iostream>
#include<algorithm>
using namespace std;
int score[100001][2];
long long d[100001][3];
int main() {

	int T, n;
	cin >> T;

	while (T--)
	{
		cin >> n;

		for (int i = 0; i <= 1; i++)
			for (int j = 1; j <= n; j++)
				cin >> score[j][i];
		
		for (int i = 1; i <= n; i++)
		{
			d[i][0] = max(d[i-1][2],max(d[i-1][0],d[i-1][1]));
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + score[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + score[i][1];
		}

		long long mS = 0;
		mS = max(d[n][0], max(d[n][1], d[n][2]));

		cout << mS << endl;
	}

	return 0;
}
