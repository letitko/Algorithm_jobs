#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector <int> node[2000];
bool DFS_possibility[2000];
bool BFS_possibility[2000];
int total_edge;
int total_node;

void DFS(int node_idx) {

	cout << node_idx << " ";
	DFS_possibility[node_idx] = true;

	for (unsigned int i = 0; i < node[node_idx].size(); i++) {
		int next_idx = node[node_idx][i];
		if (DFS_possibility[next_idx] != true) {
			DFS(next_idx);
		}
	}
	return;
}

void BFS() {

	queue <int> Queue;

	Queue.push(0);
	BFS_possibility[0] = true;

	while (!Queue.empty()) {

		int current_idx = Queue.front();
		Queue.pop();
		cout << current_idx << " ";

		for (unsigned int s = 0; s < node[current_idx].size(); s++) {
			int next_idx = node[current_idx][s];

			if (BFS_possibility[next_idx] == false) {
				BFS_possibility[next_idx] = true;
				Queue.push(next_idx);
			}

		}
	}
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

	for (int s = 0; s < total_node; s++) {
		sort(node[s].begin(), node[s].end());
	}
	DFS(0);
	cout << endl;
	BFS();
	cout << endl;

	return 0;
}