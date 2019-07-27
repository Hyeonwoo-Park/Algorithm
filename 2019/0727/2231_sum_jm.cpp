#include<iostream>
using namespace std;
int findC(int n) {

	int creator = 1;

	while (1) {

		int p, q, sum = 0;
		p = creator;

		while (p) {
			q = p % 10;
			p /= 10;
			sum += q;
			if (p == 0)
				sum += creator;
		}

		if (sum == n)
			return creator;
		else if (creator == n)
			return 0;

		creator++;
	}

}
int main() {

	int n;
	cin >> n;

	int creator = findC(n);

	cout << creator << endl;
}
