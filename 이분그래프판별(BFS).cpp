#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

vector <int> node[10000];
bool possibility[10000];
bool color[10000];
int total_edge;
int total_node;

void BFS(int idx) {

	queue <int> Queue;

	Queue.push(idx);
	color[idx] = true;
	possibility[idx] = true;

	while (!(Queue.empty())) {

		int current_idx = Queue.front();
		Queue.pop();

		for (unsigned int s = 0; s < node[current_idx].size(); s++) {
			int next_idx = node[current_idx][s];

			if (possibility[next_idx] == false) {
				possibility[next_idx] = true;
				color[next_idx] = !color[current_idx];
				Queue.push(next_idx);
			}

		}
	}
}

int flag = 0;

void BFS_ok(int idx) {

	memset(possibility, false, sizeof(possibility));
	queue <int> Queue;

	Queue.push(idx);
	possibility[idx] = true;

	while (!(Queue.empty())) {

		int current_idx = Queue.front();
		//	cout << "현재주소:" << current_idx << " 색상:" << color[current_idx] << ' ';
		Queue.pop();

		for (unsigned int s = 0; s < node[current_idx].size(); s++) {
			int next_idx = node[current_idx][s];
			if (color[current_idx] == color[next_idx]) { flag = 1; break; }
			if (flag == 1) { return; }
			if (possibility[next_idx] == false) {
				possibility[next_idx] = true;
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

	BFS(1);
	BFS_ok(1);
	if (flag == 0) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}