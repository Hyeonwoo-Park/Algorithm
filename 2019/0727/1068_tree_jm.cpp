#include <iostream>
#include <vector>
using namespace std;

struct node {
	bool isRemoved;
	int parent;
	vector<int> children;
};

node tree[50];

void remove_node(int m) {
	if (tree[m].children.size() != 0) {
		for (int i = 0; i < tree[m].children.size(); i++) {
			tree[tree[m].children[i]].isRemoved = true;
			remove_node(tree[m].children[i]);
		}
	}
}

int main() {
	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tree[i].isRemoved = false;
		tree[i].parent = x;
		if (x != -1) {
			tree[x].children.push_back(i);
		}
	}
	cin >> m;
	tree[m].isRemoved = true;
	tree[tree[m].parent].children.pop_back();
	remove_node(m);

	int ans = 0;
	for (int j = 0; j < n; j++) {
		if (tree[j].children.size()==0 && !tree[j].isRemoved)
			ans++;
	}

	cout << ans << '\n';
	return 0;
}
