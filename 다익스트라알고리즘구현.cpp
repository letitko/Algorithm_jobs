#include <iostream>
#include <vector>
using namespace std;
#define MAX 1004 

vector <int> node[MAX];
vector <int> cost[MAX];
bool check[MAX];
int table[MAX];
int all_node, all_edge, starter, ender;

int main() {

	cin >> all_node >> all_edge >> starter >> ender;
	for (int s = 0; s < all_edge; s++) {
		int st, ed, cst;
		cin >> st;
		cin >> ed;
		cin >> cst;

		node[st].push_back(ed);
		cost[st].push_back(cst);

		node[ed].push_back(st);
		cost[ed].push_back(cst);
	}

	// 모든 노드의 starter로부터 도착하는 최단경로를 알지 못하므로 미지수로 큰 값 987987987로
	// 초기화한다
	for (int s = 0; s < all_node; s++) {
		table[s] = 987987987;
	}

	table[starter] = 0;

	for (int process = 1; process <= all_node; process++) { //총 노드의 개수 만큼 반복한다

		int president_idx = -1;
		int president_value = 987987987;


		// 모든 노드에 대하여 최소값이 확정되지 않고(table[node]가 false이고,
		// false인 노드중 table[node]가 가장 작은 값은 이제
		// starter노드로 부터 최단경로로 도착 확정이 가능 한 노드 이므로 선별해낸다.
		for (int idx = 0; idx < all_node; idx++) {
			if (check[idx] == false && table[idx] < president_value) {
				president_value = table[idx];
				president_idx = idx;
			}
		}

		check[president_idx] = true; // president_idx 노드는 이제
		// starter노드로 부터 최단경로로 도착이 확정된 노드이다.


		// 최솟값이 확정된 노드를 바탕으로 인접 노드에 대하여 최소값 갱신 여부를 판단한다.
		for (unsigned int s = 0; s < node[president_idx].size(); s++) {

			int dest_node = node[president_idx][s];
			int dest_cost = cost[president_idx][s];
			// president_idx ---------(dest_cost)------------> dest_node == 동선
			// table[president)_idx]-->+(dest_cost)----------> table[dest_node] == 코스트
			// table[president_idx]에는 p_idx에 도달하기위한 최단 경로가 이미 있으니,
			// p_idx에 인접한 노드에 도달할때 자기자신 + dest_cost가 더 작으면 
			// table[dest_node]의 최소값을 갱신 시켜주라는 것이다.
			// 즉, 이런 갱신이 계속 반복되다보면 나중에 그 목적 노드도 최소값이 확정되는 것이다.

			if (table[dest_node] > table[president_idx] + dest_cost) {
				table[dest_node] = table[president_idx] + dest_cost;
			}
		}
	}

	cout << table[ender];
	return 0;
}