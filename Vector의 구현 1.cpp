#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> smith(5, 18); // vector ���̽��� ũ�⸦ int������ 5ĭ ����� �� ���� ���� 18�� �ʱ�ȭ ��Ų��.
	for (int s = 0; s < 5; s++) {
		smith[s] = s;
	}
	smith.push_back(6);
	for (int s = 0; s< 6; s++){
		cout << smith[s] << ' ';
	}
}