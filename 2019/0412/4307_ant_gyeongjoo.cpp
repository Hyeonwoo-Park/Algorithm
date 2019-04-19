#include <iostream>
#include <algorithm>
using namespace std;

int T;
int length;
int N;


int main() {
	cin >> T;

	for (int t = 1; t <= T; t++) {

		cin >> length >> N;

		int min_t=0;
		int	max_t=0;

		for (int n = 1; n <= N; n++) {
			int a;
			cin >> a;
			if(min_t < min(a, length - a)) min_t= min(a, length - a);
			if(max_t < max(a, length - a)) max_t= max(a, length - a);

		}
		
		cout << min_t << " " << max_t << '\n';
	}


	return 0;
}
