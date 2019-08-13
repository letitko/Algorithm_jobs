#include <iostream>
#define LEN 100000
using namespace std;

int get_left(int num[], int pivot, int start, int end, int left[]) {
	// 퀵솔트중 피벗숫자보다 작은 수들 즉 종결 피벗위치의 좌측을 찾아내는 함수
	int idx = 0;
	for (int s = start + 1; s <= end; s++) {
		if (num[s] <= pivot) {
			left[idx] = num[s];
			idx++;
		}
	}

	return idx; // left함수에 들어간 원소의 총 ***개수를 반환함
}

int get_right(int num[], int pivot, int start, int end, int right[]) {
	// 퀵솔트중 피벗숫자보다 큰 수들 즉 종결 피벗위치의 우측을 찾아내는 함수
	int idx = 0;
	for (int s = start + 1; s <= end; s++) {
		if (num[s] > pivot) {
			right[idx] = num[s];
			idx++;
		}
	}

	return idx; // right함수에 들어간 원소의 총 ***개수를 반환함
}

void quick_sort(int num[], int start, int end) {

	// 기저조건 원소가 하나일 경우 종료
	if (start >= end) {
		return;
	}

	// 퀵솔트를 구현하는 함수

	int pivot = num[start];
	static int left[LEN];
	static int right[LEN];

	// 피벗기준 좌측에 올 숫자들 left[LEN]에 백업하고 left[LEN]의 원소개수 획득
	int left_count = get_left(num,pivot,start,end,left); // 여기서 ***left_cnt의 값은
	//                       (left[LEN]에 들어간 원소의 개수는) pivot의 index가 될 것임

	// 피벗기준 우측에 올 숫자들 right[LEN]에 백업하고 right[LEN]의 원소개수 획득
	int right_count = get_right(num, pivot, start, end, right);

	// 배열 재정렬 시작(합성)
	// 1.피벗의 좌측 입력
	for (int n = 0; n <= left_count - 1; n++) {
		num[start + n] = left[n]; // num[]에 대입시는 start의 index기준으로 생각을 해야함
	}
	// 2.피벗입력
	num[start + left_count] = pivot; // num[]에 대입시는 start의 index기준으로 생각을 해야함

	// 3.피벗의 우측 입력
	for (int n = 0; n <= right_count-1; n++) {
		num[start + left_count + 1+ n] = right[n]; // num[]에 대입시는 start의 index기준으로 생각을 해야함
	}

	quick_sort(num, start, start + left_count - 1); // ****함수의 구간 대입시에도 start의 index기준으로 생각을 해야함
	quick_sort(num, start + left_count + 1, end); // ****함수의 구간 대입시에도 start의 index기준으로 생각을 해야함

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