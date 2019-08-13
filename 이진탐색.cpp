#include <iostream>
#define LEN 100000
using namespace std;

int binary_search(int arr[], int start, int end, int value) {

	// 이진탐색 재귀적 구현
	// ***전재조건은 순차적으로 이미 숫자들이 정렬되어있어야함

	// 기저조건
	if (start > end) { // 만약 원소가 단 하나도 없을 경우
		return -1;
	}
	else if (start == end) { // 만약 원소가 단 하나일때, 시작과 끝이 동일할때
		if (arr[start] == value) { return start; } // 마지막에 찾아낸다면 값이 존재하는 idx반환
		else { return -1; } // 못찾을 경우 -1 반환
	}

	// 기능부
	int mid = (start + end) / 2; // 중간 idx를 정해서
	if (arr[mid] == value) { return mid; } // 그값이 애초에 일치하면 일찌감치 값이 존재하는 idx반환
	else if (arr[mid] > value) { return binary_search(arr, start, mid - 1, value); } // 찾으려는 값 보다 배열의 중간값이 더 크다면- 범위설정에서 중간값은 버려도된다
	else { return binary_search(arr, mid + 1, end, value); } // 찾으려는 값 보다 배열의 중간값이 더 작다면- 범위설정에서 중간값은 버려도된다


}

int main() {
	int total_num;
	int question;
	static int arr[LEN];
	static int q_arr[LEN];
	cin >> total_num;
	cin >> question;
	for (int s = 0; s < total_num; s++) {
		cin >> arr[s];
	}
	for (int s = 0; s < question; s++) {
		cin >> q_arr[s];
	}

	for (int s = 0; s < question; s++) {
		//cout << "TEST_NUM : " << s << " " << q_arr[s] << endl;
		int result = binary_search(arr, 0, total_num - 1, q_arr[s]);
		//cout << result << " ";
		if (result == -1) { cout << "NO" << endl; }
		else { cout << "YES" << endl; }
	}
}