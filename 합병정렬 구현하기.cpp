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

	while (p <= e1 && q <= e2) { // ������ �߽����� ������ ���Ͽ� ���������� �ӽù迭�� ����
		if (arr[p] >= arr[q]) {
			temp[idx++] = arr[q]; // temp[idx]�� arr[q]�� �ְ� idx�� �ϳ� �ø�
			q++;
		}
		else {
			temp[idx++] = arr[p]; // temp[idx]�� p�� �ְ� idx�� �ϳ� �ø�
			p++;
		}
	}

	if (p > e1) { // ������ ó���ڵ�
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
	if (start >= end) { // �պ��� �迭 ���� ���Ұ� �ϳ���� merging�� �����ϱ����� ����
		return;
	}
	else {
		int mid = (start + end) / 2;
		merge_sorting(arr, start, mid); // ���� ���� ����
		merge_sorting(arr, mid + 1, end); // ������ ���� ����
		merging(arr, start, mid, mid + 1, end); // �պ�����
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