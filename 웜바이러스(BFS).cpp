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
int counter = 0;

void BFS(int idx) {

	queue <int> Queue;

	Queue.push(idx);
	color[idx] = true;
	possibility[idx] = true;

	while (!(Queue.empty())) {

		int current_idx = Queue.front();
		counter += 1;
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
	cout << counter - 1 << endl;

	return 0;
}