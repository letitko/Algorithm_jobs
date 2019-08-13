#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int total_node;
int total_edge;
int start_node;
int end_node;
queue <int> Queue;
vector <int> node[12000];
bool possibility[12000];
int node_dist[12000];

void find_short() {

	node_dist[start_node] = 0;
	possibility[start_node] = true;
	Queue.push(start_node);


	while (!Queue.empty()) {

		int current_idx = Queue.front();
		Queue.pop();

		for (int s = 0; s < node[current_idx].size(); s++) {
			if (possibility[node[current_idx][s]] == false) {
				possibility[node[current_idx][s]] = true;
				Queue.push(node[current_idx][s]);
				node_dist[node[current_idx][s]] = node_dist[current_idx] + 1;
			}
		}
		
	}

}

int main() {

	cin >> total_node;
	cin >> total_edge;

	for (int i = 0; i < total_edge; i++) {
		int st, ed;
		cin >> st >> ed;

		node[st].push_back(ed);
		node[ed].push_back(st);
	}

	cin >> start_node;
	cin >> end_node;

	find_short();

	cout << node_dist[end_node];
}