#include <iostream>
#define LEN 100000
using namespace std;

int sequence_sum(int arr[], int start, int end) {

	if (start >= end) { return arr[start]; }

	int mid = (start + end) / 2;

	int just_left = sequence_sum(arr, start, mid);
	int just_right = sequence_sum(arr, mid + 1, end);

	int mid_left_max = -789789789;
	int mid_right_max = -789789789;

	int mid_left_sum = 0;
	for (int s = mid; s >= start; s--) {
		mid_left_sum += arr[s];
		if (mid_left_sum > mid_left_max) {
			mid_left_max = mid_left_sum;
		}
	}

	int mid_right_sum = 0;
	for (int s = mid + 1; s <= end; s++) {
		mid_right_sum += arr[s];
		if (mid_right_sum > mid_right_max) {
			mid_right_max = mid_right_sum;
		}
	}

	int mid_max = mid_right_max + mid_left_max;

	if (just_left >= mid_max && just_left >= just_right) { return just_left; }
	else if (just_right >= mid_max && just_right >= just_left) { return just_right; }
	else { return mid_max; }

}

int main() {

	int total_num;
	cin >> total_num;

	int arr[LEN];

	for (int s = 0; s <= total_num; s++) {
		cin >> arr[s];
	}
	cout << sequence_sum(arr, 0, total_num - 1);
}