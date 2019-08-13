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

	//기저
	if (start >= end) {
		return;
	}

	//기능부
	int pivot = arr[start];
	static int left[LEN];
	static int right[LEN];
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

	// 이진탐색 재귀적 구현
	// ***전재조건은 순차적으로 이미 숫자들이 정렬되어있어야함

	// 기저조건
	if (start > end) { // 만약 원소가 단 하나도 없을 경우
		return -1;
	}
	else if (start == end) { // 만약 원소가 단 하나일때, 시작과 끝이 동일할때
		if (arr[start] == value) { return find_how_many(arr, start, value, end); } // 마지막에 찾아낸다면 값이 존재하는 idx반환
		else { return -1; } // 못찾을 경우 -1 반환
	}

	// 기능부
	int mid = (start + end) / 2; // 중간 idx를 정해서
	if (arr[mid] == value) { return find_how_many(arr, mid, value, end); } // 그값이 애초에 일치하면 일찌감치 값이 존재하는 idx반환
	else if (arr[mid] > value) { return binary_search(arr, start, mid - 1, value,total_num); } // 찾으려는 값 보다 배열의 중간값이 더 크다면- 범위설정에서 중간값은 버려도된다
	else { return binary_search(arr, mid + 1, end, value, total_num); } // 찾으려는 값 보다 배열의 중간값이 더 작다면- 범위설정에서 중간값은 버려도된다
	
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