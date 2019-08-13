#include <iostream>
using namespace std;
#define LEN 100000

void merging(int arr[], int s1, int e1, int s2, int e2) {
	int temp[LEN + 1];
	int idx = 1;

	int p, q;
	p = s1;
	q = s2;

	// 1 2 3 4      5 6 7 8
	// p ->           q ->

	while (p <= e1 && q <= e2) { // 절반을 중심으로 양쪽을 비교하여 순차적으로 임시배열에 정렬
		if (arr[p] >= arr[q]) {
			temp[idx++] = arr[q]; // temp[idx]에 arr[q]를 넣고 idx를 하나 올림
			q++;
		}
		else {
			temp[idx++] = arr[p]; // temp[idx]에 p를 넣고 idx를 하나 올림
			p++;
		}
	}

	if (p > e1) { // 나머지 처리코드
		while (q <= e2) {
			temp[idx++] = arr[q];
			q++;
		}
	}
	else {
		while (p <= e1) {
			temp[idx++] = arr[p];
			p++;
		}
	}

	int copy_helper = 1;
	for (int s = s1; s <= e2; s++) {
		arr[s] = temp[copy_helper];
		copy_helper++;
	}
}

void merge_sorting(int arr[], int start, int end) {
	if (start >= end) { // 합병할 배열 만약 원소가 하나라면 merging을 시작하기위한 기저
		return;
	}
	else {
		int mid = (start + end) / 2;
		merge_sorting(arr, start, mid); // 왼쪽 절반 정렬
		merge_sorting(arr, mid + 1, end); // 오른쪽 절반 정렬
		merging(arr, start, mid, mid + 1, end); // 합병개시
	}
}

int main() {
	int arr[LEN + 1];
	int n;
	cin >> n;
	for (int s = 1; s <= n; s++) {
		cin >> arr[s];
	}
	merge_sorting(arr, 1, n);
	for (int s = 1; s <= n; s++) {
		cout << arr[s] << " ";
	}
}