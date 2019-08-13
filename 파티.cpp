#include <iostream>
#include <vector>
using namespace std;
#define MAX 1004 

// ���ͽ�Ÿ �˰��򿡼� ���⼺�� ������ �˰������� �����Ͽ� ������ �ذ��Ѵ�
// �մ������� ö���� ���� ���� ������ �������̶���ϸ� -> case.1
// ö���������� �մ����� ���� ������ �������̶�� �ΰ� �ذ��Ͽ� -> case.2
// ������ case.1 + case.2�� �ȴ�.

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

	// ��� ����� starter�κ��� �����ϴ� �ִܰ�θ� ���� ���ϹǷ� �������� ū �� 987987987��
	// �ʱ�ȭ�Ѵ�
	for (int s = 1; s <= all_node; s++) { 
		table[s] = 987987987;
	}

	table[starter] = 0;

	for (int process = 1; process <= all_node; process++) { //�� ����� ���� ��ŭ �ݺ��Ѵ�

		int president_idx = -1;
		int president_value = 987987987;

		// ��� ��忡 ���Ͽ� �ּҰ��� Ȯ������ �ʰ�(table[node]�� false�̰�,
		// false�� ����� table[node]�� ���� ���� ���� ����
		// starter���� ���� �ִܰ�η� ���� Ȯ���� ���� �� ��� �̹Ƿ� �����س���.
		for(int idx=1;idx<=all_node;idx++){
			if (check[idx] == false && table[idx] < president_value) {
				president_value = table[idx];
				president_idx = idx;
			}
		}

		check[president_idx] = true; // president_idx ���� ����
		// starter���� ���� �ִܰ�η� ������ Ȯ���� ����̴�.


		// �ּڰ��� Ȯ���� ��带 �������� ���� ��忡 ���Ͽ� �ּҰ� ���� ���θ� �Ǵ��Ѵ�.
		for (unsigned int s = 0; s < node[president_idx].size(); s++) {

			int dest_node = node[president_idx][s];
			int dest_cost = cost[president_idx][s];
			// president_idx ---------(dest_cost)------------> dest_node == ����
			// table[president)_idx]-->+(dest_cost)----------> table[dest_node] == �ڽ�Ʈ
			// table[president_idx]���� p_idx�� �����ϱ����� �ִ� ��ΰ� �̹� ������,
			// p_idx�� ������ ��忡 �����Ҷ� �ڱ��ڽ� + dest_cost�� �� ������ 
			// table[dest_node]�� �ּҰ��� ���� �����ֶ�� ���̴�.
			// ��, �̷� ������ ��� �ݺ��Ǵٺ��� ���߿� �� ���� ��嵵 �ּҰ��� Ȯ���Ǵ� ���̴�.

			if (table[dest_node] > table[president_idx] + dest_cost) {
				table[dest_node] = table[president_idx] + dest_cost;
			}
		}
	}

	// ��� ����� starter�κ��� �����ϴ� �ִܰ�θ� ���� ���ϹǷ� �������� ū �� 987987987��
	// �ʱ�ȭ�Ѵ�
	for (int r = 1; r <= all_node; r++) {
		r_table[r] = 987987987;
	}

	r_table[starter] = 0;

	for (int process = 1; process <= all_node; process++) { //�� ����� ���� ��ŭ �ݺ��Ѵ�

		int r_president_idx = -1;
		int r_president_value = 987987987;

		// ��� ��忡 ���Ͽ� �ּҰ��� Ȯ������ �ʰ�(table[node]�� false�̰�,
		// false�� ����� table[node]�� ���� ���� ���� ����
		// starter���� ���� �ִܰ�η� ���� Ȯ���� ���� �� ��� �̹Ƿ� �����س���.
		for (int idx = 1; idx <= all_node; idx++) {
			if (r_check[idx] == false && r_table[idx] < r_president_value) {
				r_president_value = r_table[idx];
				r_president_idx = idx;
			}
		}

		r_check[r_president_idx] = true; // president_idx ���� ����
		// starter���� ���� �ִܰ�η� ������ Ȯ���� ����̴�.


		// �ּڰ��� Ȯ���� ��带 �������� ���� ��忡 ���Ͽ� �ּҰ� ���� ���θ� �Ǵ��Ѵ�.
		for (unsigned int s = 0; s < r_node[r_president_idx].size(); s++) {

			int dest_node = r_node[r_president_idx][s];
			int dest_cost = r_cost[r_president_idx][s];
			// president_idx ---------(dest_cost)------------> dest_node == ����
			// table[president)_idx]-->+(dest_cost)----------> table[dest_node] == �ڽ�Ʈ
			// table[president_idx]���� p_idx�� �����ϱ����� �ִ� ��ΰ� �̹� ������,
			// p_idx�� ������ ��忡 �����Ҷ� �ڱ��ڽ� + dest_cost�� �� ������ 
			// table[dest_node]�� �ּҰ��� ���� �����ֶ�� ���̴�.
			// ��, �̷� ������ ��� �ݺ��Ǵٺ��� ���߿� �� ���� ��嵵 �ּҰ��� Ȯ���Ǵ� ���̴�.

			if (r_table[dest_node] > r_table[r_president_idx] + dest_cost) {
				r_table[dest_node] = r_table[r_president_idx] + dest_cost;
			}
		}
	}

	int counter = 0 ;
	int r_counter = 0;

	for(int s=1;s<=all_node;s++){
		counter += table[s]; // ö���� ������ �մ������� ���� ���
		r_counter += r_table[s]; // �մ������� ö���׷� ���� ���
	}

	cout << counter + r_counter << endl;
	return 0;
}