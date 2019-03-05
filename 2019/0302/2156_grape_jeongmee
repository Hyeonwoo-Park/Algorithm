#include<iostream>
#include<algorithm>
using namespace std;
int grape[10001];
long long d[10001];
int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> grape[i];

	d[1] = grape[1];
	d[2] = grape[1] + grape[2];

	for (int i = 3; i <= n; i++)
	{
		d[i] = d[i - 1];//안 마신 경우
		if (d[i] < d[i - 2] + grape[i])
			d[i] = d[i - 2] + grape[i]; // 직전 포도주 X, 현재 마신 경우
		if (d[i] < d[i - 3] + grape[i - 1] + grape[i])
			d[i] = d[i - 3] + grape[i - 1] + grape[i]; //2번 전의 포도주 X, 현재, 직전 포도주 마신 경우
	}

	cout << d[n] << endl;

	return 0;
}
