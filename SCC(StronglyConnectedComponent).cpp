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

int finished_time[MAX]; // �� ��尡 �������� �ð� ��� ���̺�
int clock_counter = 1; // ����������(��尡 �Ұ��� �������� �ð��� ���) �ð� ��Ͽ�
bool possibility[MAX]; // �湮���� Ž��

int order[MAX];
int order_len = 0;
bool possibility2[MAX];
int group[MAX]; // group[s] : ���� s�� ���� �׷��� ��ȣ�� ������
int group_cnt = 1; // �׷��� �ű�� ���ؼ�

void get_time(int node) {
	// node���� �����ؼ� DFS�� �ϸ鼭, ���������� ������� �ð��� ���

	possibility[node] = true;

	for (unsigned int s = 0; s < list[node].size(); s++) {
		int node2 = list[node][s];

		// node�� ����� node2�� ���Ͽ� ��ȸ // DFS �ݺ�
		if (!possibility[node2]) {
			get_time(node2);
		}

	}

	// ��ȯ�� ������ �ڱ� �ڽ��� ���̻� �Ұ��� ������ �ð��� ���

	finished_time[node] = clock_counter;
	clock_counter +=1;

	// �ð��� �޾ƿ����� �� ��尡 ���������� �ð��� ������ �� ������ ���� �� ���� ����.
	// �׷��Ƿ� ���������� ���� ���������� ��带 order[MAX]�� �켱������ �����ص�.
	
	order[order_len] = node;
	order_len += 1;

}

void get_my_group(int r_node) {
	// r_node�������� DFS, ������ �Ųٷε� �׷����� ���ؼ�, DFS�� ����
	// �׷�ȭ�� ������

	possibility2[r_node] = true;
	group[r_node] = group_cnt;

	for (unsigned int s = 0; s < reverselist[r_node].size(); s++) {
		int r_node_s_linked_node = reverselist[r_node][s];
		// r_node ------------> r_node_s_linked_node
		// r_node ���� r_node_slinked_node�� ���Ͽ� �����
		
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

		// a���� -> b�� �����

		list[a].push_back(b); // ������ �׷��� ���� ����
		reverselist[b].push_back(a); // ������ �׷��� ���� ����
	}

	// DFS�� �ϸ鼭 ���������� ������� �ð��� ���
	// ���������� �ð��� ������� �����
	// �� �ð� ���̺��� ���� ������ = ������ �׷������� ���������� �ð��� ū ������ ��ȸ�ϰ� �� ����
	// �� �� �� ��带 �������� ��ȸ�ϸ� ������ ���� ��� ���� �׷��� �Ǵ� ����.

	for (int s = 1; s <= n; s++) { // ������ �ð��� ����
		if (possibility[s]==false) {
			get_time(s);
		}
	}

	// �ð��� �޾ƿ����� �� ��尡 ���������� finished_time[MAX]�� �����Ͽ� �� ��尡 ��������(���� ����) �ð��� ������ �� ������ ���� �� ���� ����.
	// ���� get_time �Լ��� order[MAX]�� ���������� �ð��� ���� ���� ����(�������� ������ ����ȣ)�� ������� ����. // get_time �Լ� �Ϻ� ����
	
	// ��, ���� order[MAX]�� ������ �׷������� ���������°� ���� �������� ����Ǿ�����,
	// ������ �׷�������, ������ �׷������� �ű� ���ڰ� ū ��(���)�� ���ܳ��� ������� �̿��Ͽ� ������ DFS�� ���Ͽ� SCC �׷�ȭ�� ������

	for (int s = order_len - 1; s >= 0; s--) {
		int r_node = order[s];

		// ������ �׷��������� �������� ���� ���� ū ��� = ��,������ �׷������� �ű� ���ڰ� ū ��(���)�� ���Ͽ�
		// DFS���Ͽ� ��ȸ�ϸ� ���� ��� ��带 �ϳ��� �׷����� ������.
		if (!possibility2[r_node]) {
			get_my_group(r_node);
			group_cnt+=1;
		}

	}

	cout << group_cnt - 1 << endl;

	return 0;
}