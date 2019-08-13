#include <iostream>
using namespace std;

int node[100][100] = { 0, };
int final_depth = 0;

void tree_depth(int parent, int son, int b_parent, int b_son, int total_node, int count) {

	parent = son;

	for (int s = 0; s < total_node; s++) {
		if (node[parent][s] == 0) {
			if (count > final_depth) {
				final_depth = count;
			}
		}
		else if (parent == b_son && s == b_parent) {
			if (count > final_depth) {
				final_depth = count;
			}
		}
		else {
			tree_depth(parent, s, parent, s, total_node, count + 1);
		}
	}

	return;
}


int main() {
	int total_node;
	int root_node;
	cin >> total_node;
	cin >> root_node;

	for (int s = 1; s < total_node; s++) {
		int first;
		int second;
		cin >> first;
		cin >> second;
		node[first][second] = 1;
		node[second][first] = 1;
	}

	for (int s = 0; s < total_node; s++) {
		if (node[root_node][s] == 0) { continue; }
		else tree_depth(root_node, s, root_node, s, total_node, 1);
	}
	cout << final_depth;
}