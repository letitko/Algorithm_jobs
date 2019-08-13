#include <iostream>
#define LEN 300000
#define Q_LEN 500000
using namespace std;

int get_left(int arr[], int pivot, int start, int end, int left[]) {

	int idx = 0;

	for (int s = start; s <= end; s++) {
		if (arr[s] <= pivot) {
			left[idx] = arr[s];
			idx++;
		}
	}
	return idx;
}

int get_right(int arr[], int pivot, int start, int end, int right[]) {

	int idx = 0;

	for (int s = start; s <= end; s++) {
		if (arr[s] > pivot) {
			right[idx] = arr[s];
			idx++;
		}
	}
	return idx;
}

void quick_sort(int arr[], int start, int end) {

	//����
	if (start >= end) {
		return;
	}

	//��ɺ�
	int pivot = arr[start];
	static int left[LEN];
	static int right[LEN];
	int left_cnt = get_left(arr, pivot, start + 1, end, left); // �ǹ����� ������ �迭�� ���ڰ����� ����
	int right_cnt = get_right(arr, pivot, start + 1, end, right); // �ǹ����� ������ �迭�� ���ڰ����� ����

	//�ռ���
	for (int s = 0; s <= left_cnt - 1; s++) {
		arr[start + s] = left[s];
	}

	arr[start + left_cnt] = pivot;

	for (int s = 0; s <= right_cnt - 1; s++) {
		arr[start + left_cnt + 1 + s] = right[s];
	}

	//��ͺ�
	quick_sort(arr, start, start + left_cnt - 1);
	quick_sort(arr, start + left_cnt + 1, end);

}

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
	else if (arr[mid] > value) { binary_search(arr, start, mid - 1, value); } // ã������ �� ���� �迭�� �߰����� �� ũ�ٸ�- ������������ �߰����� �������ȴ�
	else { binary_search(arr, mid + 1, end, value); } // ã������ �� ���� �迭�� �߰����� �� �۴ٸ�- ������������ �߰����� �������ȴ�


}

int main() {
	int total_num;
	static int arr[LEN];
	int question;
	static int q_arr[Q_LEN];
	cin >> total_num;
	for (int s = 0; s < total_num; s++) {
		cin >> arr[s];
	}

	quick_sort(arr, 0, total_num - 1); // �� ����

	//for (int s = 0; s < total_num; s++) { // Ȯ��
	//	cout <<  arr[s] << ' ';
	//} cout << endl;

	cin >> question;
	for (int s = 0; s < question; s++) {
		cin >> q_arr[s];
	}

	for (int s = 0; s < question; s++) {
		//cout << "TEST_NUM : " << s << " " << q_arr[s] << endl;
		int result = binary_search(arr, 0, total_num - 1, q_arr[s]);
		//cout << result << " ";
		if (result == -1) { cout << "0" << endl; }
		else { cout << "1" << endl; }
	}
}