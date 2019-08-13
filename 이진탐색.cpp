#include <iostream>
#define LEN 100000
using namespace std;

int binary_search(int arr[], int start, int end, int value) {

	// ����Ž�� ����� ����
	// ***���������� ���������� �̹� ���ڵ��� ���ĵǾ��־����

	// ��������
	if (start > end) { // ���� ���Ұ� �� �ϳ��� ���� ���
		return -1;
	}
	else if (start == end) { // ���� ���Ұ� �� �ϳ��϶�, ���۰� ���� �����Ҷ�
		if (arr[start] == value) { return start; } // �������� ã�Ƴ��ٸ� ���� �����ϴ� idx��ȯ
		else { return -1; } // ��ã�� ��� -1 ��ȯ
	}

	// ��ɺ�
	int mid = (start + end) / 2; // �߰� idx�� ���ؼ�
	if (arr[mid] == value) { return mid; } // �װ��� ���ʿ� ��ġ�ϸ� ���ġ ���� �����ϴ� idx��ȯ
	else if (arr[mid] > value) { return binary_search(arr, start, mid - 1, value); } // ã������ �� ���� �迭�� �߰����� �� ũ�ٸ�- ������������ �߰����� �������ȴ�
	else { return binary_search(arr, mid + 1, end, value); } // ã������ �� ���� �迭�� �߰����� �� �۴ٸ�- ������������ �߰����� �������ȴ�


}

int main() {
	int total_num;
	int question;
	static int arr[LEN];
	static int q_arr[LEN];
	cin >> total_num;
	cin >> question;
	for (int s = 0; s < total_num; s++) {
		cin >> arr[s];
	}
	for (int s = 0; s < question; s++) {
		cin >> q_arr[s];
	}

	for (int s = 0; s < question; s++) {
		//cout << "TEST_NUM : " << s << " " << q_arr[s] << endl;
		int result = binary_search(arr, 0, total_num - 1, q_arr[s]);
		//cout << result << " ";
		if (result == -1) { cout << "NO" << endl; }
		else { cout << "YES" << endl; }
	}
}