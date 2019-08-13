#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

//       2---1
//       |  /|
//       | / |
//  5----4   3
//  |________/

// 5 6 -> n m
// 1 2
// 1 3
// 1 4
// 2 4
// 3 5
// 4 5

int main() {
	vector <int> nodes[MAX];

	int n, m;
	cin >> n >> m;
	for (int s = 0; s < m; s++) {
		int start, end;
		cin >> start >> end;
		nodes[start].push_back(end); // �ش� ��� ����Ʈ�� ������� ����
		nodes[end].push_back(start); // �ش� ��� ����Ʈ�� ������� ������ ����
	}

	for (int s = 0; s <= n; s++) {
		cout << s << " : ";

		// node[s]�� ����Ʈ�� �ִ� ��Ҹ� ����Ѵ�
		for (int t = 1; t < nodes[s].size(); t++) {
			cout << nodes[s][t] << ' '; // s��° ����� �迭 �� t�ε����� ���� �� ���
			// �̰��� ������ ���� nodes[s]��ü�� �迭�� �̸��� �Ǳ�빮�� X[idx]�ÿ� ���Ͽ� X�� �����Ϳ� ��� �迭�� �������ּҶ��
			// nodes[s]��ü�� �����Ϳ� ��� �迭���̹Ƿ� X�� ��ü�Ͽ� X[t]�� ���� ����� ��밡���� ���̴�.
		} cout << endl;

	}
}