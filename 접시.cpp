#include <iostream>
#include <string.h>
using namespace std;

int get_left(char num[], char pivot, int start, int end, char left[]) {
	// ����Ʈ�� �ǹ����ں��� ���� ���� �� ���� �ǹ���ġ�� ������ ã�Ƴ��� �Լ�
	int idx = 0;
	for (int s = start + 1; s <= end; s++) {
		if (num[s] <= pivot) {
			left[idx] = num[s];
			idx++;
		}
	}

	return idx; // left�Լ��� �� ������ �� ***������ ��ȯ��
}

int get_right(char num[], char pivot, int start, int end, char right[]) {
	// ����Ʈ�� �ǹ����ں��� ū ���� �� ���� �ǹ���ġ�� ������ ã�Ƴ��� �Լ�
	int idx = 0;
	for (int s = start + 1; s <= end; s++) {
		if (num[s] > pivot) {
			right[idx] = num[s];
			idx++;
		}
	}

	return idx; // right�Լ��� �� ������ �� ***������ ��ȯ��
}

void quick_sort(char num[], int start, int end) {

	// �������� ���Ұ� �ϳ��� ��� ����
	if (start >= end) {
		return;
	}

	// ����Ʈ�� �����ϴ� �Լ�

	char pivot = num[start];
	static char left[28];
	static char right[28];

	// �ǹ����� ������ �� ���ڵ� left[LEN]�� ����ϰ� left[LEN]�� ���Ұ��� ȹ��
	int left_count = get_left(num, pivot, start, end, left); // ���⼭ ***left_cnt�� ����
	//                       (left[LEN]�� �� ������ ������) pivot�� index�� �� ����

	// �ǹ����� ������ �� ���ڵ� right[LEN]�� ����ϰ� right[LEN]�� ���Ұ��� ȹ��
	int right_count = get_right(num, pivot, start, end, right);

	// �迭 ������ ����(�ռ�)
	// 1.�ǹ��� ���� �Է�
	for (int n = 0; n <= left_count - 1; n++) {
		num[start + n] = left[n]; // num[]�� ���Խô� start�� index�������� ������ �ؾ���
	}
	// 2.�ǹ��Է�
	num[start + left_count] = pivot; // num[]�� ���Խô� start�� index�������� ������ �ؾ���

	// 3.�ǹ��� ���� �Է�
	for (int n = 0; n <= right_count - 1; n++) {
		num[start + left_count + 1 + n] = right[n]; // num[]�� ���Խô� start�� index�������� ������ �ؾ���
	}

	quick_sort(num, start, start + left_count - 1); // ****�Լ��� ���� ���Խÿ��� start�� index�������� ������ �ؾ���
	quick_sort(num, start + left_count + 1, end); // ****�Լ��� ���� ���Խÿ��� start�� index�������� ������ �ؾ���

}

class stack {
public:
	char data[26]; // �����ͷ�

	int how_many = 0; // ���Ұ���
	int size = 0; // �ִ���밳��

	void create(int s) { // �ִ���������
		size = s;
	}

	void push(int insert_data) {
		if (how_many >= size) {
			cout << "Overflow" << endl;
		}
		else {
			data[how_many] = insert_data; // �ε������� ������ �Է�
			how_many++; // ��������
		}
	}

	void pop() {
		if (how_many <= 0) {
			cout << "Underflow" << endl;
		}
		else {
			data[how_many - 1] = 0; // �ε������� �������ϳ� ����
			how_many--; // ��������
		}
	}

	char top() {
		// �����Ͱ� ���� ���  -1 ����
		if (how_many <= 0) {
			return -1;
		}
		else {
			return data[how_many - 1];// �ε������� ���� �ֻ��� �������ϳ� ���
		}
	}

};

int main() {
	char menu[28];
	char menu_b[28];
	memset(menu, NULL, sizeof(menu));
	fgets(menu, sizeof(menu), stdin);
	memcpy(menu_b, menu, sizeof(menu_b));

	int idx = 0;
	while (1) {
		if (menu_b[idx] == NULL) {
			break;
		}
		idx++;
	} idx -= 1;
	//	cout << idx << endl;

	quick_sort(menu_b, 0, idx);

	//	for (int s = 0; s <= idx; s++) {
	//		cout << menu[s];
	//	} cout << endl;

	//	for (int s = 0; s <= idx; s++) {
	//		cout << menu_b[s];
	// } cout << endl;

	stack dishes;
	dishes.create(26);

	int m_idx = 0;
	for (int s = 0; s <= idx; s++) {
		dishes.push(menu_b[s]);
		while (dishes.top() == menu[m_idx]) {
			{
				dishes.pop();
				m_idx++;
			}
		}
	}

	int flag = 0;
	if (dishes.how_many <= 0) {
		flag = 1;
	}

	if (flag == 1) {
		stack dishes2;
		dishes2.create(idx + 1);
		int menu_idx = 0;
		for (int s = 0; s <= idx; s++) {
			dishes2.push(menu_b[s]);
			cout << "push" << endl;
			while (dishes2.top() == menu[menu_idx]) {
				{
					dishes2.pop();
					menu_idx++;
					cout << "pop" << endl;
				}
			}
		}
	}
	else {
		cout << "impossible" << endl;
	}
}