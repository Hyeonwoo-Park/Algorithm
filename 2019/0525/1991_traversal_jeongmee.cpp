#include <iostream>

using namespace std;

struct Node {
	char _leftChild;
	char _rightChild;
};

Node d[26];

void preorder(int n) {

	cout << (char)(n + 'A');

	if (d[n]._leftChild != '.') preorder((int)(d[n]._leftChild - 'A'));
	if (d[n]._rightChild != '.') preorder((int)(d[n]._rightChild - 'A'));
}

void inorder(int n) {

	if (d[n]._leftChild != '.') inorder((int)(d[n]._leftChild - 'A'));

	cout << (char)(n + 'A');

	if (d[n]._rightChild != '.') inorder((int)(d[n]._rightChild - 'A'));
}

void postorder(int n) {

	if (d[n]._leftChild != '.') postorder((int)(d[n]._leftChild - 'A'));
	if (d[n]._rightChild != '.') postorder((int)(d[n]._rightChild - 'A'));

	cout << (char)(n + 'A');
}

int main() {

	int n;
	cin >> n;

	while (n--) {

		char c = 0;
		cin >> c;
		cin >> d[c - 'A']._leftChild >> d[c - 'A']._rightChild;
	}

	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';

	return 0;
}
