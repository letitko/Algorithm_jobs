#include <iostream>
#include <string.h>
using namespace std;

class stack {
public:
	char data[32]; // �����ͷ�
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
	char sample[32];
	memset(sample, NULL, sizeof(sample));
	fgets(sample, sizeof(sample), stdin);

	int idx = 0;
	while (1) {
		if (sample[idx] == NULL) {
			break;
		}
		idx++;
	} idx -= 1; // idx ����

	// cout << idx << endl;

	if (idx % 2 == 0) { cout << '0' << endl; return 0; }

	stack op;
	op.create(32);
	int is_error = 0;

	for (int s = 0; s <= idx; s++) { // ������ ���� ���κ��� Ȯ��
		if (op.how_many <= 0) { // �����Ͱ� �ϳ��� ������
			if (sample[s] == ')' || sample[s] == ']') {
				//cout << "error_1" << endl;
				is_error = 1;
				break;
			}
			else {
				op.push(sample[s]);
			}
		}
		else { // �����Ͱ� �ϳ��� �����Ҷ�
			if (sample[s] == ')') {
				if (op.top() == '(') {
					op.pop();
				}
				else {
					//cout << "error_2" << endl;
					is_error = 1;
					break;
				}
			}
			else if (sample[s] == ']') {
				if (op.top() == '[') {
					op.pop();
				}
				else {
					//cout << "error_3" << endl;
					is_error = 1;
					break;
				}
			}
			else {
				op.push(sample[s]);
			}
		}

	}

	if (is_error == 1) {
		cout << "0" << endl;
	}
	else {
		int temp = 1;
		int result = 0;
		int turn_on = 0;
		for (int s = 0; s <= idx; s++) {
			if (sample[s] == '(') {
				op.push(sample[s]);
				temp *= 2;
				turn_on = 1;
			}
			else if (sample[s] == '[') {
				op.push(sample[s]);
				temp *= 3;
				turn_on = 1;
			}
			else if (sample[s] == ')') {
				op.pop();
				if (turn_on == 1) {
					result += temp;
					turn_on = 0;
				}
				temp /= 2;
			}
			else {
				op.pop();
				if (turn_on == 1) {
					result += temp;
					turn_on = 0;
				}
				temp /= 3;
			}
			// cout << "process : " << s << result << endl;
		}
		cout << result;
	}
}