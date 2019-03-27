#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int t;
	cin >> t;

	for (int test = 1; test <= t; test++)
	{
		int n;
		vector <int> v;
		int minimum = 0;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());

		int i = 0;
		if (v[i + 2] - v[i] > minimum)
			minimum = v[i + 2] - v[i];

		i = n - 1;

		if (v[i] - v[i - 2] > minimum)
			minimum = v[i] - v[i - 2];

		for (int i = 1; i < n - 1; i += 2)
		{
			if (v[i] - v[i - 1] > minimum)
				minimum = v[i] - v[i - 1];
			else if (v[i + 1] - v[i] > minimum)
				minimum = v[i + 1] - v[i];
		}

		cout << '#' << test << ' ' << minimum << '\n';
	}
	return 0;
}
