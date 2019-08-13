#include <iostream>
#include <string.h>
using namespace std;

class stack {
public:
	long long int data [500000]; // �����ͷ�
	long long int how_many = 0; // ���Ұ���
	long long int size = 0; // �ִ���밳��
	void create(int s) { // �ִ���������
		size = s;
	}

	void push(long long int insert_data) {
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

	long long int top() {
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
	stack top; // ���� ����
	stack top_idx;
	top.create(500000); // ���� ������ ����
	top_idx.create(500000); // ���� ������ ����
	long long int total; // ž�� ��
	long long int height; // ���� ����
	long long int cnt = 0; // idx ī����
	cin >> total;

	top.push(0);
	top_idx.push(0);

	for (int s = 0; s < total; s++) {
		cin >> height; // ������� �Է�

		while (height >= top.top()) {
			if (top.how_many <= 0) { break;	}
			top.pop(); // �ڽź��� ���� idx�� ������ �� �ʿ� ��� ����
			top_idx.pop();
		}

		if (top.how_many<=0) { // �� �������� ���� 0 �̶�� 
			cout << "0" << ' '; // 0�� ����Ѵ�
			cnt += 1; // idx����� idx
			top.push(height); // ������ �����͸� �Է��ϰ�
			top_idx.push(cnt);
		}

		else { // �� �������� ���� 0���� ũ�ٴ°�
				cout << top_idx.top() << ' ';
				top.push(height);
				cnt += 1;
				top_idx.push(cnt);
		}
	}

}
