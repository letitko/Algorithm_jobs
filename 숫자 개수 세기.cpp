#include <iostream>
#define LEN 100000
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

int find_how_many(int *arr, int idx, int value, int total_num) {
	int count = 1;

	int forward_idx = idx + 1;
	int backward_idx = idx - 1;

	if (forward_idx <= total_num) {
		while (arr[forward_idx] == value)
		{
			forward_idx += 1;
			count += 1;
			if (forward_idx > total_num) {
				break;
			}
		}
	}

		if(backward_idx >= 0){
			while (arr[backward_idx] == value)
			{
				backward_idx-=1;
				count += 1;
				if (backward_idx < 0) {
				break;
				}
			}
		}
	return count;
}

int binary_search(int arr[], int start, int end, int value, int total_num) {

	// ����Ž�� ����� ����
	// ***���������� ���������� �̹� ���ڵ��� ���ĵǾ��־����

	// ��������
	if (start > end) { // ���� ���Ұ� �� �ϳ��� ���� ���
		return -1;
	}
	else if (start == end) { // ���� ���Ұ� �� �ϳ��϶�, ���۰� ���� �����Ҷ�
		if (arr[start] == value) { return find_how_many(arr, start, value, end); } // �������� ã�Ƴ��ٸ� ���� �����ϴ� idx��ȯ
		else { return -1; } // ��ã�� ��� -1 ��ȯ
	}

	// ��ɺ�
	int mid = (start + end) / 2; // �߰� idx�� ���ؼ�
	if (arr[mid] == value) { return find_how_many(arr, mid, value, end); } // �װ��� ���ʿ� ��ġ�ϸ� ���ġ ���� �����ϴ� idx��ȯ
	else if (arr[mid] > value) { return binary_search(arr, start, mid - 1, value,total_num); } // ã������ �� ���� �迭�� �߰����� �� ũ�ٸ�- ������������ �߰����� �������ȴ�
	else { return binary_search(arr, mid + 1, end, value, total_num); } // ã������ �� ���� �迭�� �߰����� �� �۴ٸ�- ������������ �߰����� �������ȴ�
	
}

int main() {
	int total_num;
	int total_q_num;

	cin >> total_num;
	cin >> total_q_num;

	static int arr[LEN];
	static int q_arr[LEN];

	for (int s = 0; s < total_num; s++) {
		cin >> arr[s];
	}

	for (int s = 0; s < total_q_num; s++) {
		cin >> q_arr[s];
	}

	quick_sort(arr, 0, total_num-1);

	// for (int s = 0; s < total_num; s++) {
	// 	cout << arr[s] << ' ' ;
	// } cout << endl;

	for (int s=0;s<total_q_num;s++){
		if (binary_search(arr, 0, total_num - 1, q_arr[s], total_num-1) == -1) {
			cout << 0 << endl;
		}
		else { cout << binary_search(arr, 0, total_num - 1, q_arr[s], total_num-1) << endl; }
	}
	
}