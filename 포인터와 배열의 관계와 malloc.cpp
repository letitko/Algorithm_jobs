#include <iostream>
using namespace std;

int main() {

	int *ptr = (int *)malloc(sizeof(int) * 10);

	//������ ���� �ڵ�� �Ʒ��� �迭 ����� ������ �����ϴ�.
	/*
		int ptr[10];
	*/


	*ptr = 10;
	*(ptr + 1) = 20;
	*(ptr + 2) = 30;

	for (int s = 0; s < 10; s++) {
		if (*(ptr + s) == NULL) { continue; }
		cout << *(ptr + s) << " ";
	}
	
	cout << endl;

	// �׷��� ���⼭ ���� �����
	// ���� �����Ϳ� malloc �ּ��ڵ��
	// �ᱹ �迭�� �����ϱ����� ������ �Լ��� ��������
	// �˼� �ִ�.

	for (int s = 0; s < 10; s++) {
		if (ptr[s] == NULL) { continue; }
		cout << ptr[s] << " ";
	}
}