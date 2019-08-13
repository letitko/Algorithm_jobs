#include <iostream>
#include <vector>
using namespace std;
#define MAX 1004 

// 다익스타 알고리즘에서 방향성을 가지는 알고리즘으로 변경하여 문제를 해결한다
// 손님집에서 철수네 집을 가는 방향을 역방향이라고하면 -> case.1
// 철수네집에서 손님집을 가는 방향을 순방향이라고 두고 해결하여 -> case.2
// 정답은 case.1 + case.2가 된다.

vector <int> node[MAX];
vector <int> r_node[MAX];
vector <int> cost[MAX];
vector <int> r_cost[MAX];

bool check[MAX];
bool r_check[MAX];
int table[MAX];
int r_table[MAX];
int all_node, all_edge, starter;

int main() {

	cin >> all_node >> all_edge >> starter;
	for (int s = 0; s < all_edge; s++) {
		int st, ed, cst;
		cin >> st;
		cin >> ed;
		cin >> cst;

		node[st].push_back(ed);
		cost[st].push_back(cst);

		r_node[ed].push_back(st);
		r_cost[ed].push_back(cst);
	}

	// 모든 노드의 starter로부터 도착하는 최단경로를 알지 못하므로 미지수로 큰 값 987987987로
	// 초기화한다
	for (int s = 1; s <= all_node; s++) { 
		table[s] = 987987987;
	}

	table[starter] = 0;

	for (int process = 1; process <= all_node; process++) { //총 노드의 개수 만큼 반복한다

		int president_idx = -1;
		int president_value = 987987987;

		// 모든 노드에 대하여 최소값이 확정되지 않고(table[node]가 false이고,
		// false인 노드중 table[node]가 가장 작은 값은 이제
		// starter노드로 부터 최단경로로 도착 확정이 가능 한 노드 이므로 선별해낸다.
		for(int idx=1;idx<=all_node;idx++){
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

	// 모든 노드의 starter로부터 도착하는 최단경로를 알지 못하므로 미지수로 큰 값 987987987로
	// 초기화한다
	for (int r = 1; r <= all_node; r++) {
		r_table[r] = 987987987;
	}

	r_table[starter] = 0;

	for (int process = 1; process <= all_node; process++) { //총 노드의 개수 만큼 반복한다

		int r_president_idx = -1;
		int r_president_value = 987987987;

		// 모든 노드에 대하여 최소값이 확정되지 않고(table[node]가 false이고,
		// false인 노드중 table[node]가 가장 작은 값은 이제
		// starter노드로 부터 최단경로로 도착 확정이 가능 한 노드 이므로 선별해낸다.
		for (int idx = 1; idx <= all_node; idx++) {
			if (r_check[idx] == false && r_table[idx] < r_president_value) {
				r_president_value = r_table[idx];
				r_president_idx = idx;
			}
		}

		r_check[r_president_idx] = true; // president_idx 노드는 이제
		// starter노드로 부터 최단경로로 도착이 확정된 노드이다.


		// 최솟값이 확정된 노드를 바탕으로 인접 노드에 대하여 최소값 갱신 여부를 판단한다.
		for (unsigned int s = 0; s < r_node[r_president_idx].size(); s++) {

			int dest_node = r_node[r_president_idx][s];
			int dest_cost = r_cost[r_president_idx][s];
			// president_idx ---------(dest_cost)------------> dest_node == 동선
			// table[president)_idx]-->+(dest_cost)----------> table[dest_node] == 코스트
			// table[president_idx]에는 p_idx에 도달하기위한 최단 경로가 이미 있으니,
			// p_idx에 인접한 노드에 도달할때 자기자신 + dest_cost가 더 작으면 
			// table[dest_node]의 최소값을 갱신 시켜주라는 것이다.
			// 즉, 이런 갱신이 계속 반복되다보면 나중에 그 목적 노드도 최소값이 확정되는 것이다.

			if (r_table[dest_node] > r_table[r_president_idx] + dest_cost) {
				r_table[dest_node] = r_table[r_president_idx] + dest_cost;
			}
		}
	}

	int counter = 0 ;
	int r_counter = 0;

	for(int s=1;s<=all_node;s++){
		counter += table[s]; // 철수네 집에서 손님집으로 가는 경우
		r_counter += r_table[s]; // 손님집에서 철수네로 가는 경우
	}

	cout << counter + r_counter << endl;
	return 0;
}