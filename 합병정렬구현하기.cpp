#include <iostream>
#include <string.h>
#define LEN 100000
using namespace std;

void merge_sorting(int *arr,int start, int end) {

	if (start >= end) { return; }
	
	int mid = (start + end) / 2;

	merge_sorting(arr, start, mid);
	merge_sorting(arr, mid + 1, end);

	int new_arr[LEN];
	int new_arr_idx = 0;
	int left_idx = start;
	int right_idx = mid + 1;

	while (left_idx <= mid && right_idx <= end) {
		if (arr[left_idx] <= arr[right_idx]) {
			new_arr[new_arr_idx] = arr[left_idx];
			left_idx++;
			new_arr_idx++;
		}
		else {
			new_arr[new_arr_idx] = arr[right_idx];
			right_idx++;
			new_arr_idx++;
		}
	}

	while (left_idx <= mid) {
		new_arr[new_arr_idx] = arr[left_idx];
		new_arr_idx++;
		left_idx++;
	}
	while (right_idx <= end) {
		new_arr[new_arr_idx] = arr[right_idx];
		new_arr_idx++;
		right_idx++;
	}

	int temp_idx = 0;
	for (int s = start; s <= end; s++) {
		arr[s] = new_arr[temp_idx];
		temp_idx++;
	}
}

int main() {
	int arr[LEN];
	
	int total;
	cin >> total;
	for (int s = 0; s < total; s++) {
		cin >> arr[s];
	}
	merge_sorting(arr, 0, total - 1);
	for (int s = 0; s < total; s++) {
		cout << arr[s] << ' ';
	} cout << endl;

}