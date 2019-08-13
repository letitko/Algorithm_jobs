#include <iostream>
using namespace std;

int total_num;
int arr[100000];

int get_left(int start, int end, int pivot, int *left) {
	int idx = 0;

	for (int s = start; s <= end; s++) {
		if (arr[s] <= pivot) {
			left[idx] = arr[s];
			idx++;
		}
	}

	return idx;
}

int get_right(int start, int end, int pivot, int *right) {
	int idx = 0;

	for (int s = start; s <= end; s++) {
		if (arr[s] > pivot) {
			right[idx] = arr[s];
			idx++;
		}
	}

	return idx;
}

void quick_sort(int start, int end) {
	if (start >= end) {
		return;
	}

	int left[100000];
	int right[100000];

	int pivot = arr[start];
	int left_cnt = get_left(start + 1, end, pivot, left);
	int right_cnt = get_right(start + 1, end, pivot, right);

	for (int s = 0; s < left_cnt; s++) {
		arr[start + s] = left[s];
	}

	arr[start + left_cnt] = pivot;

	for (int s = 0; s < right_cnt; s++) {
		arr[start + left_cnt + 1 + s] = right[s];
	}

	quick_sort(start, start + left_cnt - 1);
	quick_sort(start + left_cnt + 1, end);
}

int main() {
	cin >> total_num;

	for (int s = 0; s < total_num; s++) {
		cin >> arr[s];
	}

	quick_sort(0, total_num - 1);

	for (int s = 0; s < total_num; s++) {
		cout << arr[s] << ' ';
	} cout << endl;

	return 0;
}