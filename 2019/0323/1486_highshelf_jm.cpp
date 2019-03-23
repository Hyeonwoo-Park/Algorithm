#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
int minimum, n, b;
void solve(int num) {
	int tmp1 = v.size();
	for (int i = 0; i < tmp1; i++)
	{
		int tmp2 = 0;
		tmp2 = v[i] + num;
		if (tmp2 >= b)
		{
			if (tmp2 - b < minimum)
				minimum = tmp2 - b;
		}
		v.push_back(tmp2);
	}
}
int main() {
	int t;
	cin >> t;

	for (int test = 1; test <= t; test++)
	{
		int h[20];
		cin >> n >> b;
		for (int i = 0; i < n; i++)
		{
			cin >> h[i];
		}
		minimum = 99999;
		v.clear();
		v.push_back(0);
		
		for (int i = 0; i < n; i++)
		{
			solve(h[i]);
		}
		
		cout << '#' << test << ' ' << minimum << '\n';
	}

	return 0;
}
