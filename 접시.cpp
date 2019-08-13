#include <iostream>
#include <string.h>
using namespace std;

int get_left(char num[], char pivot, int start, int end, char left[]) {
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

int get_right(char num[], char pivot, int start, int end, char right[]) {
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

void quick_sort(char num[], int start, int end) {

	// 기저조건 원소가 하나일 경우 종료
	if (start >= end) {
		return;
	}

	// 퀵솔트를 구현하는 함수

	char pivot = num[start];
	static char left[28];
	static char right[28];

	// 피벗기준 좌측에 올 숫자들 left[LEN]에 백업하고 left[LEN]의 원소개수 획득
	int left_count = get_left(num, pivot, start, end, left); // 여기서 ***left_cnt의 값은
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
	for (int n = 0; n <= right_count - 1; n++) {
		num[start + left_count + 1 + n] = right[n]; // num[]에 대입시는 start의 index기준으로 생각을 해야함
	}

	quick_sort(num, start, start + left_count - 1); // ****함수의 구간 대입시에도 start의 index기준으로 생각을 해야함
	quick_sort(num, start + left_count + 1, end); // ****함수의 구간 대입시에도 start의 index기준으로 생각을 해야함

}

class stack {
public:
	char data[26]; // 데이터량

	int how_many = 0; // 원소개수
	int size = 0; // 최대수용개수

	void create(int s) { // 최대수용수한정
		size = s;
	}

	void push(int insert_data) {
		if (how_many >= size) {
			cout << "Overflow" << endl;
		}
		else {
			data[how_many] = insert_data; // 인덱스기준 데이터 입력
			how_many++; // 개수증가
		}
	}

	void pop() {
		if (how_many <= 0) {
			cout << "Underflow" << endl;
		}
		else {
			data[how_many - 1] = 0; // 인덱스기준 데이터하나 삭제
			how_many--; // 개수감소
		}
	}

	char top() {
		// 데이터가 없을 경우  -1 리턴
		if (how_many <= 0) {
			return -1;
		}
		else {
			return data[how_many - 1];// 인덱스기준 스택 최상위 데이터하나 출력
		}
	}

};

int main() {
	char menu[28];
	char menu_b[28];
	memset(menu, NULL, sizeof(menu));
	fgets(menu, sizeof(menu), stdin);
	memcpy(menu_b, menu, sizeof(menu_b));

	int idx = 0;
	while (1) {
		if (menu_b[idx] == NULL) {
			break;
		}
		idx++;
	} idx -= 1;
	//	cout << idx << endl;

	quick_sort(menu_b, 0, idx);

	//	for (int s = 0; s <= idx; s++) {
	//		cout << menu[s];
	//	} cout << endl;

	//	for (int s = 0; s <= idx; s++) {
	//		cout << menu_b[s];
	// } cout << endl;

	stack dishes;
	dishes.create(26);

	int m_idx = 0;
	for (int s = 0; s <= idx; s++) {
		dishes.push(menu_b[s]);
		while (dishes.top() == menu[m_idx]) {
			{
				dishes.pop();
				m_idx++;
			}
		}
	}

	int flag = 0;
	if (dishes.how_many <= 0) {
		flag = 1;
	}

	if (flag == 1) {
		stack dishes2;
		dishes2.create(idx + 1);
		int menu_idx = 0;
		for (int s = 0; s <= idx; s++) {
			dishes2.push(menu_b[s]);
			cout << "push" << endl;
			while (dishes2.top() == menu[menu_idx]) {
				{
					dishes2.pop();
					menu_idx++;
					cout << "pop" << endl;
				}
			}
		}
	}
	else {
		cout << "impossible" << endl;
	}
}