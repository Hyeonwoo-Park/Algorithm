#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

	int t;
	scanf("%d", &t);
	
	for (int test = 1; test <= t; test++)
	{
		int n;
		char ch[3][30001];
		int s[3] = { 0, };
		int up = 0;
		scanf("%d", &n);
		scanf("%s %s %s", &ch[0], &ch[1], &ch[2]);

		for (int i = 0; i < n; i++)
		{
			if (ch[0][i] == ch[1][i] && ch[1][i] == ch[2][i])
			{
				s[0]++;
				s[1]++;
				s[2]++;
			}
			else if (ch[0][i] == ch[1][i])
			{
				s[0]++;
				s[1]++;
			}
			else if (ch[2][i] == ch[1][i])
			{
				s[2]++;
				s[1]++;
			}
			else if (ch[0][i] == ch[2][i])
			{
				s[0]++;
				s[2]++;
			}
			else
				up++;
		}

		while (up--)
		{
			sort(s, s + 3);
			s[0]++;
		}
		sort(s, s + 3);
		while (1)
		{
			if (s[0] >= s[1])
				break;
			s[0]++;
			s[1]--;
		}
		printf("#%d %d\n", test, s[1]);
	}

	return 0;
}
