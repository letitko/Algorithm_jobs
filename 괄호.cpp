#include <iostream>
using namespace std;

class stack {
public:
	char data[51]; // �����ͷ�
	int how_many = 0; // ���Ұ���
	int size = 0; // �ִ���밳��

	void create(int s) { // �ִ���������
		size = s;
	}

	void push(char insert_data) {
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

	int top() {
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

	stack s;
	s.create(50);

	char sample[51];
	int total_num;
	fgets(sample, sizeof(sample), stdin);
	for (int s = 0; s <= 50; s++) {
		if (sample[s] == NULL) {
			total_num = s; // ���� ������ ������ �� ���� �ľ�
			break;
		}
	}

	int flag = 0;
	for (int t = 0; t < total_num; t++) {
		if (sample[t] == '(') {
			s.push('(');
		}
		else if (sample[t] == ')' && s.how_many == 0) { flag = 1; break; }
		else if (sample[t] == ')' && s.how_many != 0) { s.pop(); }
		else { break; }
	}

	if (s.how_many == 0 && flag == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}