#include <iostream>
long long d[31];
using namespace std;

int main()
{
	int N; //N must be an even number.
	cin >> N;
	d[0] = 1;
	
	for (int i = 1; i <= N; i++) {
		d[i] = 3 * d[i - 2];
		for (int k = 2; i - 2 * k >= 0; k++) {
			d[i] += 2 * d[i - 2 * k];
		}
	}
	
	cout << "ans= " << d[N] << '\n';
	return 0;
}

