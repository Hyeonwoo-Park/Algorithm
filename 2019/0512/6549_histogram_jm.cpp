#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int a[100000];

int main() {

	while (1) {
		int n;
		memset(a, 0, sizeof(a));
		scanf("%d", &n);

		if (n == 0)
			break;

		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		stack<int> s;
		long long ans = 0;

		for (int i = 0; i < n; i++) {
			int left = i;
			while (!s.empty() && a[s.top()] > a[i]) {
				long long height = a[s.top()];
				s.pop();
				long long width = i;
				if (!s.empty()) {
					width = (i - s.top() - 1);
				}
				if (ans < width * height) {
					ans = width * height;
				}
			}
			s.push(i);
		}

		while (!s.empty()) {
			long long height = a[s.top()];
			s.pop();
			long long width = n;
			if (!s.empty()) {
				width = n - s.top() - 1;
			}
			if (ans < width * height) {
				ans = width * height;
			}
		}

		printf("%lli\n", ans);
	}
	return 0;
}
