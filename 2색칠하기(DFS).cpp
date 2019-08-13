#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector <int> node[10000];
bool DFS_possibility[10000];
int DFS_color[10000];
int total_edge;
int total_node;

void DFS(int node_idx) {

	DFS_possibility[node_idx] = true;

	for (unsigned int i = 0; i < node[node_idx].size(); i++) {
		int next_idx = node[node_idx][i];
		if (DFS_color[next_idx] == 2) {
			if (DFS_color[node_idx] == 0) {
				DFS_color[next_idx] = 1;
			}
			else {
				DFS_color[next_idx] = 0;
			}
		}
	}

	for (unsigned int i = 0; i < node[node_idx].size(); i++) {
		int next_idx = node[node_idx][i];
		if (DFS_possibility[next_idx] == false) {
			DFS(next_idx);
		}
	}

	return;
}

int flag = 0;

void DFS_ok(int node_idx) {
	//cout << node_idx << ' ';
	if (flag == 1) { return; }
	DFS_possibility[node_idx] = true;

	for (unsigned int i = 0; i < node[node_idx].size(); i++) {
		int next_idx = node[node_idx][i];
		if (DFS_color[node_idx] == DFS_color[next_idx]) {
			flag = 1;
		}
		if (flag == 1) {
			return;
		}
	}

	for (int i = 0; i < node[node_idx].size(); i++) {
		int next_idx = node[node_idx][i];
		if (DFS_possibility[next_idx] == false) {
			DFS_ok(next_idx);
		}
	}
	return;
}

int main() {
	cin >> total_node;
	cin >> total_edge;

	for (int s = 0; s < total_edge; s++) {
		int st; int ed;
		cin >> st >> ed;
		node[st].push_back(ed);
		node[ed].push_back(st);
	}

	for (int s = 1; s < total_node; s++) {
		DFS_color[s] = 2;
	}

	DFS_color[0] = 0;
	DFS(0);

	//for (int s = 0; s < total_node; s++) {
	//	cout << "노드명 : " << s << " 색상 : " << DFS_color[s] << ' ';
	//} cout << endl;

	for (int s = 0; s < total_node; s++) {
		DFS_possibility[s] = false;
	}
	//memset(DFS_possibility, false, sizeof(DFS_possibility));

	DFS_ok(0);

	if (flag == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}