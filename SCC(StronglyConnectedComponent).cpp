#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1001;

vector <int> list[MAX];
vector <int> reverselist[MAX];
int n, m;
// n => total_node;
// m => total_edge;

int finished_time[MAX]; // 각 노드가 빠져나온 시간 기록 테이블
int clock_counter = 1; // 빠져나오는(노드가 할것이 없어지는 시간을 기록) 시간 기록용
bool possibility[MAX]; // 방문여부 탐색

int order[MAX];
int order_len = 0;
bool possibility2[MAX];
int group[MAX]; // group[s] : 정점 s가 속한 그룹의 번호를 저장함
int group_cnt = 1; // 그룹을 매기는 기준수

void get_time(int node) {
	// node부터 시작해서 DFS를 하면서, 빠져나오는 순서대로 시간을 기록

	possibility[node] = true;

	for (unsigned int s = 0; s < list[node].size(); s++) {
		int node2 = list[node][s];

		// node에 연결된 node2에 대하여 조회 // DFS 반복
		if (!possibility[node2]) {
			get_time(node2);
		}

	}

	// 순환이 끝나고 자기 자신이 더이상 할것이 없으면 시간을 기록

	finished_time[node] = clock_counter;
	clock_counter +=1;

	// 시간을 받아왔지만 각 노드가 빠져나오는 시간은 알지만 그 순서를 아직 잘 알지 못함.
	// 그러므로 빠져나갈때 먼저 빠져나오는 노드를 order[MAX]에 우선적으로 저장해둠.
	
	order[order_len] = node;
	order_len += 1;

}

void get_my_group(int r_node) {
	// r_node에서부터 DFS, 하지만 거꾸로된 그래프에 대해서, DFS를 통해
	// 그룹화를 진행함

	possibility2[r_node] = true;
	group[r_node] = group_cnt;

	for (unsigned int s = 0; s < reverselist[r_node].size(); s++) {
		int r_node_s_linked_node = reverselist[r_node][s];
		// r_node ------------> r_node_s_linked_node
		// r_node 에서 r_node_slinked_node를 향하여 연결됨
		
		if (possibility2[r_node_s_linked_node] == false) {
			get_my_group(r_node_s_linked_node);
		}

	}

}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		// a에서 -> b로 연결됨

		list[a].push_back(b); // 정방향 그래프 정보 생성
		reverselist[b].push_back(a); // 역방향 그래프 정보 생성
	}

	// DFS를 하면서 빠져나오는 순서대로 시간을 기록
	// 빠져나오는 시간을 순서대로 기록함
	// 이 시간 테이블을 토대로 뒤집은 = 역방향 그래프에서 빠져나오는 시간이 큰 노드부터 순회하게 될 것임
	// 이 때 한 노드를 기준으로 순회하며 만나는 노드는 모두 같은 그룹이 되는 것임.

	for (int s = 1; s <= n; s++) { // 각자의 시간을 정함
		if (possibility[s]==false) {
			get_time(s);
		}
	}

	// 시간을 받아왔지만 각 노드가 빠져나오는 finished_time[MAX]에 저장하여 각 노드가 빠져나온(할일 다한) 시간은 알지만 그 순서를 아직 잘 알지 못함.
	// 따라서 get_time 함수에 order[MAX]에 빠져나오는 시간이 가장 빠른 순서(작은값을 가지는 노드번호)를 기록해줄 것임. // get_time 함수 하부 참조
	
	// 자, 이제 order[MAX]에 순방향 그래프에서 빠져나오는게 빠른 순서부터 저장되었으니,
	// 역방향 그래프에서, 순방향 그래프에서 매긴 숫자가 큰 값(노드)이 말단노드로 변경됨을 이용하여 역방향 DFS를 통하여 SCC 그룹화를 진행함

	for (int s = order_len - 1; s >= 0; s--) {
		int r_node = order[s];

		// 역방향 그래프에서의 빠져나온 순서 값이 큰 노드 = 즉,순방향 그래프에서 매긴 숫자가 큰 값(노드)에 대하여
		// DFS통하여 순회하며 만난 모든 노드를 하나의 그룹으로 묶어줌.
		if (!possibility2[r_node]) {
			get_my_group(r_node);
			group_cnt+=1;
		}

	}

	cout << group_cnt - 1 << endl;

	return 0;
}