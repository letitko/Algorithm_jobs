#include <iostream>
#define LEN 100000
using namespace std;

int get_left(int num[], int pivot, int start, int end, int left[]) {
	// ����Ʈ�� �ǹ����ں��� ���� ���� �� ���� �ǹ���ġ�� ������ ã�Ƴ��� �Լ�
	int idx = 0;
	for (int s = start + 1; s <= end; s++) {
		if (num[s] <= pivot) {
			left[idx] = num[s];
			idx++;
		}
	}

	return idx; // left�Լ��� �� ������ �� ***������ ��ȯ��
}

int get_right(int num[], int pivot, int start, int end, int right[]) {
	// ����Ʈ�� �ǹ����ں��� ū ���� �� ���� �ǹ���ġ�� ������ ã�Ƴ��� �Լ�
	int idx = 0;
	for (int s = start + 1; s <= end; s++) {
		if (num[s] > pivot) {
			right[idx] = num[s];
			idx++;
		}
	}

	return idx; // right�Լ��� �� ������ �� ***������ ��ȯ��
}

void quick_sort(int num[], int start, int end) {

	// �������� ���Ұ� �ϳ��� ��� ����
	if (start >= end) {
		return;
	}

	// ����Ʈ�� �����ϴ� �Լ�

	int pivot = num[start];
	static int left[LEN];
	static int right[LEN];

	// �ǹ����� ������ �� ���ڵ� left[LEN]�� ����ϰ� left[LEN]�� ���Ұ��� ȹ��
	int left_count = get_left(num,pivot,start,end,left); // ���⼭ ***left_cnt�� ����
	//                       (left[LEN]�� �� ������ ������) pivot�� index�� �� ����

	// �ǹ����� ������ �� ���ڵ� right[LEN]�� ����ϰ� right[LEN]�� ���Ұ��� ȹ��
	int right_count = get_right(num, pivot, start, end, right);

	// �迭 ������ ����(�ռ�)
	// 1.�ǹ��� ���� �Է�
	for (int n = 0; n <= left_count - 1; n++) {
		num[start + n] = left[n]; // num[]�� ���Խô� start�� index�������� ������ �ؾ���
	}
	// 2.�ǹ��Է�
	num[start + left_count] = pivot; // num[]�� ���Խô� start�� index�������� ������ �ؾ���

	// 3.�ǹ��� ���� �Է�
	for (int n = 0; n <= right_count-1; n++) {
		num[start + left_count + 1+ n] = right[n]; // num[]�� ���Խô� start�� index�������� ������ �ؾ���
	}

	quick_sort(num, start, start + left_count - 1); // ****�Լ��� ���� ���Խÿ��� start�� index�������� ������ �ؾ���
	quick_sort(num, start + left_count + 1, end); // ****�Լ��� ���� ���Խÿ��� start�� index�������� ������ �ؾ���

}



int main() {

	static int arr[LEN];

	int n;
	cin >> n;
	for (int s = 0; s < n; s++) {
		cin >> arr[s];
	}
	quick_sort(arr, 0, n - 1);

	for (int s = 0; s < n; s++) {
		cout << arr[s] << ' ';
	} cout << endl;

	return 0;
}