#include <iostream>
#include <vector>
#define MAX 1004
using namespace std;

vector <int> node[MAX];
vector <int> cost[MAX];
int p_table[MAX];
int f_table[MAX];
int r_table[MAX];
bool f_check[MAX];
bool r_check[MAX];
bool p_check[MAX];

int starter, ender, point_a, point_b;
int all_node, all_edge;

int main() {

	cin >> all_node >> all_edge;
	starter = 1; ender = all_node;

	for (int process = 1; process <= all_edge; process++) {
		int st, ed, cst;
		cin >> st >> ed >> cst;

		node[st].push_back(ed);
		cost[st].push_back(cst);

		node[ed].push_back(st);
		cost[ed].push_back(cst);
	}

	cin >> point_a >> point_b;

	for (int s = 1; s <= all_node; s++) {
		f_table[s] = 987987987;
	}

	for (int s = 1; s <= all_node; s++) {
		r_table[s] = 987987987;
	}

	for (int s = 1; s <= all_node; s++) {
		p_table[s] = 987987987;
	}

	f_table[starter] = 0;
	r_table[ender] = 0;
	p_table[point_a] = 0;

	for (int process = 1; process <= all_node; process++) {

		int f_president_idx_value = 987987987;
		int f_president_idx = -1;

		int r_president_idx_value = 987987987;
		int r_president_idx = -1;

		int p_president_idx_value = 987987987;
		int p_president_idx = -1;

		for (int s = 1; s <= all_node; s++) {
			if (!f_check[s] && f_table[s] < f_president_idx_value) {
				f_president_idx_value = f_table[s];
				f_president_idx = s;
			}
		}

		f_check[f_president_idx] = true;

		for (int s = 1; s <= all_node; s++) {
			if (!r_check[s] && r_table[s] < r_president_idx_value) {
				r_president_idx_value = r_table[s];
				r_president_idx = s;
			}
		}

		r_check[r_president_idx] = true;

		for (int s = 1; s <= all_node; s++) {
			if (!p_check[s] && p_table[s] < p_president_idx_value) {
				p_president_idx_value = p_table[s];
				p_president_idx = s;
			}
		}

		p_check[p_president_idx] = true;

		for (int s = 0; s < node[f_president_idx].size(); s++) {
			int dest_idx = node[f_president_idx][s];
			int dest_cost = cost[f_president_idx][s];

			if (f_table[dest_idx] > f_table[f_president_idx] + dest_cost) {
				f_table[dest_idx] = f_table[f_president_idx] + dest_cost;
			}
		}

		for (int s = 0; s < node[p_president_idx].size(); s++) {
			int dest_idx = node[p_president_idx][s];
			int dest_cost = cost[p_president_idx][s];

			if (p_table[dest_idx] > p_table[p_president_idx] + dest_cost) {
				p_table[dest_idx] = p_table[p_president_idx] + dest_cost;
			}
		}

		for (int s = 0; s < node[r_president_idx].size(); s++) {
			int dest_idx = node[r_president_idx][s];
			int dest_cost = cost[r_president_idx][s];

			if (r_table[dest_idx] > r_table[r_president_idx] + dest_cost) {
				r_table[dest_idx] = r_table[r_president_idx] + dest_cost;
			}
		}

	}

	int case_1 = f_table[point_a] + p_table[point_b] + r_table[point_b];
	int case_2 = f_table[point_b] + p_table[point_b] + r_table[point_a];

	cout << (case_1 > case_2 ? case_2 : case_1) << endl;
}