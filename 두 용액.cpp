#include <iostream>
#include <algorithm>
#include <string.h>
#define LEN 100000
using namespace std;
// -49934 49933

int get_left(long long int arr[], long long int pivot, int start, int end, long long int left[]) {

	int idx = 0;

	for (int s = start; s <= end; s++) {
		if (arr[s] <= pivot) {
			left[idx] = arr[s];
			idx++;
		}
	}
	return idx;
}

int get_right(long long int arr[], long long int pivot, int start, int end, long long int right[]) {

	int idx = 0;

	for (int s = start; s <= end; s++) {
		if (arr[s] > pivot) {
			right[idx] = arr[s];
			idx++;
		}
	}
	return idx;
}

void quick_sort(long long int arr[], int start, int end) {

	//기저
	if (start >= end) {
		return;
	}

	//기능부
	long long int pivot = arr[start];
	static long long int left[LEN];
	static long long int right[LEN];
	int left_cnt = get_left(arr, pivot, start + 1, end, left); // 피벗기준 좌측단 배열의 숫자개수를 지님
	int right_cnt = get_right(arr, pivot, start + 1, end, right); // 피벗기준 우측단 배열의 숫자개수를 지님

	//합성부
	for (int s = 0; s <= left_cnt - 1; s++) {
		arr[start + s] = left[s];
	}

	arr[start + left_cnt] = pivot;

	for (int s = 0; s <= right_cnt - 1; s++) {
		arr[start + left_cnt + 1 + s] = right[s];
	}

	//재귀부
	quick_sort(arr, start, start + left_cnt - 1);
	quick_sort(arr, start + left_cnt + 1, end);
}

int binary_search(int long long arr[], int start, int end, int long long value) {

	// 이진탐색 재귀적 구현
	// ***전재조건은 순차적으로 이미 숫자들이 정렬되어있어야함

	// 기저조건
	if (start >= end) { // 만약 원소가 단 하나도 없을 경우
		return start;
	}


	// 기능부
	int mid = (start + end) / 2; // 중간 idx를 정해서
	if (arr[mid] == value) { return mid; } // 그값이 애초에 일치하면 일찌감치 값이 존재하는 idx반환
	else if (arr[mid] > value) { binary_search(arr, start, mid - 1, value); } // 찾으려는 값 보다 배열의 중간값이 더 크다면- 범위설정에서 중간값은 버려도된다
	else { binary_search(arr, mid + 1, end, value); } // 찾으려는 값 보다 배열의 중간값이 더 작다면- 범위설정에서 중간값은 버려도된다

}

long long int abs_binary_search(int long long arr[], int start, int end, int long long minus_value) {

	if (end - start <= 1) {
		if (abs(arr[start] + minus_value) <= abs(arr[end] + minus_value)) {
			return arr[start];
		}
		else {
			return arr[end];
		}
	}

	// 기능부
	int mid = (start + end) / 2;
	if (arr[mid] + minus_value == 0) { return arr[mid]; }
	else if (arr[mid] + minus_value < 0) { abs_binary_search(arr, mid, end, minus_value); }
	else { abs_binary_search(arr, start, mid, minus_value); }

}

int main() {

	int total_num;
	cin >> total_num;

	static long long int arr[LEN];

	for (int s = 0; s < total_num; s++) {
		cin >> arr[s];
	} // quick_sort(arr, 0, total_num - 1); // 퀵 솔팅 실행
	sort(arr, arr + total_num);

	if (arr[0] >= 0 && arr[total_num - 1] >= 0) { // 전체 양수
		cout << arr[0] << " " << arr[1] << endl;
	}
	else if (arr[0] <= 0 && arr[total_num - 1] <= 0) { // 전체 음수
		cout << arr[total_num - 2] << " " << arr[total_num - 1] << endl;
	}
	else { // 양음 공존

		int minus_idx = binary_search(arr, 0, total_num - 1, 0);
		while (arr[minus_idx] >= 0) {
			minus_idx--;
		}
		long long int abs_value = 789789789789789;
		long long int first_value = 0;
		long long int second_value = 0;

		for (int s = 0; s <= minus_idx; s++) {
			if (abs_value == 0) { break; }

			if (abs_value > abs(arr[s] + abs_binary_search(arr, minus_idx + 1, total_num - 1, arr[s])))
			{
				first_value = arr[s];
				second_value = abs_binary_search(arr, minus_idx + 1, total_num - 1, arr[s]);
				abs_value = abs(arr[s] + abs_binary_search(arr, minus_idx + 1, total_num - 1, arr[s]));
			}
		}

		if (abs(arr[minus_idx - 1] + arr[minus_idx]) < abs_value) {
			first_value = arr[minus_idx - 1];
			second_value = arr[minus_idx];
			abs_value = abs(arr[minus_idx - 1] + arr[minus_idx]);
		}
		if (abs(arr[minus_idx + 1] + arr[minus_idx + 2]) < abs_value) {
			first_value = arr[minus_idx + 1];
			second_value = arr[minus_idx + 2];
			abs_value = abs(arr[minus_idx + 1] + arr[minus_idx + 2]);
		}

		if (first_value <= second_value) {
			cout << first_value << ' ' << second_value << endl;
		}
		else {
			cout << second_value << ' ' << first_value << endl;
		}
	}

	return 0;
}