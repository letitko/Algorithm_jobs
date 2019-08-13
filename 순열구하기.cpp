#include <iostream>
using namespace std;
// 97 = 'a'

bool del_occasion(char temp[], char arr, int n_idx) {
	
	for(int s=0;s<n_idx;s++){
		if (temp[s] == arr) {
			return 1;
		}
	}
	return 0;
}

void recursion(char arr[], char temp[], int dest_idx, int n_idx, int count) {


	if (n_idx == count) { // ���� Ż�� ����
		for (int s = 0; s < count; s++) {
			cout << temp[s];
		}
		cout << endl; return;
	}

	for (int idx = 0; idx < dest_idx; idx++) { // ����ϱ�
		if(del_occasion(temp, arr[idx], n_idx)) { continue; }	// ����ġ��
		temp[n_idx] = arr[idx];
		recursion(arr, temp, dest_idx, n_idx + 1, count);
	}


}



int main() {

	char arr[26]; // �迭
	char temp[26]; // �ӽ� �����
	int idx = 0; // �ε���
	for (int s = 97; s <= 97 + 25; s++) {
		arr[idx] = s;
		idx++;
	} //���ĺ� �Է�

	int n_idx = 0;

	int dest_idx;
	int count;

	cin >> dest_idx;
	cin >> count;

	recursion(arr, temp, dest_idx, n_idx, count);
	return 0;
}