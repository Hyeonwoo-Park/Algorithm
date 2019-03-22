#include <iostream>
#include <algorithm>
//#define MIN(a,b)= ((a)<(b)?(a):(b))

using namespace std;
long long five, two;

int main(void) {
	long long n, m;
	cin >> n >> m;

	five = 0;
	two = 0;

	for (long long i = 2; i <= n; i *= 2) {
		two += n / i;
	}
	for (long long i = 2; i <= n; i *= 2) {
		two -= m / i;
	}
	for (long long i = 2; i <= n; i *= 2) {
		two -= (n-m)/ i;
	}

	for (long long i = 5; i <= n; i *= 5) {
		five += n / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		five -= m / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		five -= (n-m) / i;
	}

	cout << min(two, five) << '\n';
	
}




/* ///직접 구현해보려 했으나 큰 수에서 동작..X
long long find_five(long long x) {
	five = 0;

	while (x % 5 == 0) {
		five++;
		x /= 5;
	}

	return five;
}

long long find_two(long long x) {
	two = 0;

	while (x % 2 == 0) {
		two++;
		x /= 2;
	}

	return two;
}

int factorial(int x) {
	if (x == 0) {
		return 1;
	}
	else {
		return x * factorial(x - 1);
	}
}

int main(void) {
	
	int n, m;

	
	cin >> n >> m;

	//cout << find_five(1000000000000) << '\n';

	
	long long ans_five = find_five(factorial(n)) - find_five(factorial(m)) - find_five(factorial(n - m));
	long long ans_two = find_two(factorial(n)) - find_two(factorial(m)) - find_two(factorial(n - m));

	
	cout <<"n! = " << factorial(n) << '\n';
	cout << "m! = " << factorial(m) << '\n';
	cout << "(n-m)! = " << factorial(n-m) << '\n';

	cout << "n!의 5의 갯수 = " << find_five(factorial(n)) << '\n';


	cout <<"5의 갯수 =" << ans_five << '\n';
	cout << "2의 갯수 =" << ans_two << '\n';


	cout << min(ans_five,ans_two) << '\n';
	

	return 0;
}
*/
