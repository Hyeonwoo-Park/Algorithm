#include <iostream>

using namespace std;

int index[12][2];
char arr[1025][2050];

void movePosition(int n) {

	for (int i = index[n - 1][0] - 1; i >= 0; i--) {
		for (int j = 0; j < index[n - 1][1]; j++) {
			if (n % 2) {
				arr[i + index[n - 1][0]][j + index[n - 1][0] + 1] = arr[i][j];
				arr[i][j] = ' ';
			}
			else {
				arr[i + 1][j + index[n - 1][0] + 1] = arr[i][j];
				arr[i][j] = ' ';
			}
		}
	}
}

void makeTriangle(int n) {

	for (int i = 0; i < index[n][0]; i++) {
		for (int j = 0; j < index[n][1]; j++) {
			if (n % 2) {
				if (i == index[n][0] - 1) {
					arr[i][j] = '*';
				}
				else {
					if (index[n][1] / 2 + i == j || index[n][1] / 2 - i == j)
						arr[i][j] = '*';
				}
			}
			else {
				if (i == 0) {
					arr[i][j] = '*';
				}
				else {
					if (j == i || index[n][1] - 1 - j == i)
						arr[i][j] = '*';
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i, j;
	cin >> n;

	arr[0][0] = '*';
	index[1][0] = 1;

	for (int i = 1; i <= n; i++) {
		index[i][1] = index[i][0] * 2 - 1;
		index[i + 1][0] = index[i][0] * 2 + 1;
	}

	for (i = 2; i <= n; i++) {

		movePosition(i);

		makeTriangle(i);
	}

	for (i = 0; i < index[n][0]; i++) {
		if (n % 2) {
			for (j = 0; j < index[n][1] / 2 + i + 1; j++) {
				if(arr[i][j] == '*')
					cout << arr[i][j];
				else cout << ' ';
			}
		}
		else {
			for (j = 0; j < index[n][1] - i; j++) {
				if (arr[i][j] == '*')
					cout << arr[i][j];
				else cout << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
