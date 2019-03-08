#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
int v[10001];
int d[10001];
int main()
{
	int n;
	cin >> n;

	//vector<int> v;
	//int a;

	/*
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	*/

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	d[1] = v[1];
	d[2] = v[1] + v[2];
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1];
		if (d[i] < d[i - 2] + v[i])	d[i] = d[i - 2] + v[i];
		if (d[i] < d[i - 3] + v[i - 1] + v[i]) d[i] = d[i - 3] + v[i - 1] + v[i];

	}




	//d[i] = v[i] 까지 마셨을때 최대 포도주 양
	/*
	d[0] = v[0];
	d[1] = v[0] + v[1];
	d[2] = v[0]+v[1];
	if (d[2] < v[0] + v[2]) d[2] = v[0] + v[2];
	if (d[2] < v[1] + v[2]) d[2] = v[1] + v[2];
	
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1];
		if (d[i] < d[i - 2] + v[i]) {
			d[i] = d[i - 2] + v[i];
		}
		if (d[i] < d[i - 3] + v[i] + v[i - 1]) {
			d[i] = d[i - 3] + v[i] + v[i - 1];
		}
	}
	*/



	cout <<"ans="<< d[n] << '\n';

	return 0;
}

