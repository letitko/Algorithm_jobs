#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> arr;

	arr.push_back(1); // �迭�� �ڸ��ϳ� �ø��� ������ 1 �����ض�
	arr.push_back(2); // �迭�� �ڸ��ϳ� �ø��� ������ 2 �����ض�
	arr.push_back(3); // �迭�� �ڸ��ϳ� �ø��� ������ 3 �����ض�

	cout << arr[0] << arr[1] << arr[2] << endl;

	arr.pop_back(); // �迭 �� ���ڸ� ������ �ϳ� ������ ũ�� �ϳ� �ٿ���

	cout << arr.size() << endl; // ��� ũ�� 2

	arr.resize(10, 5);

	for (int s = 0; s < arr.size(); s++) {
		cout << arr[s] << ' ';
	} cout << endl; // 1 2 5 5 5 5 5 5 5 5 ���

	arr.resize(5); // ũ�⸦ 10���� 5�� �ٽ� �ٿ�����

	for (int s = 0; s < arr.size(); s++) {
		cout << arr[s] << ' ';
	} cout << endl; // 1 2 5 5 5 ���

	return 0;
}