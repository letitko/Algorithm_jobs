#include <iostream>
using namespace std;

int binary_search(int arr[], int start, int end, int value) {

	// 이진탐색 재귀적 구현
	// ***전재조건은 순차적으로 이미 숫자들이 정렬되어있어야함

	// 기저조건
	if (start > end) { // 만약 원소가 단 하나도 없을 경우
		return -1;
	}
	else if (start == end) { // 만약 원소가 단 하나일때, 시작과 끝이 동일할때
		if (arr[start] == value) { return arr[start]; } // 마지막에 찾아낸다면 값이 존재하는 idx반환
		else { return -1; } // 못찾을 경우 -1 반환
	}

	// 기능부
	int mid = (start + end) / 2; // 중간 idx를 정해서
	if (arr[mid] == value) { return arr[mid]; } // 그값이 애초에 일치하면 일찌감치 값이 존재하는 idx반환
	else if (arr[mid] > value) { binary_search(arr, start, mid - 1, value); } // 찾으려는 값 보다 배열의 중간값이 더 크다면- 범위설정에서 중간값은 버려도된다
	else { binary_search(arr, mid + 1, end, value); } // 찾으려는 값 보다 배열의 중간값이 더 작다면- 범위설정에서 중간값은 버려도된다

}


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
	static int left[1000];
	static int right[1000];

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
	int data[1000]; // 데이터량
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

	int top() {
		// 데이터가 없을 경우  -1 리턴
		if (how_many <= 0) {
			return -1;
		}
		else {
			return data[how_many - 1];// 인덱스기준 스택 최상위 데이터하나 출력
		}
	}

};

stack stack_X;
stack stack_Y;

class nodes {
public:
	int ndx = 0;
	int sub[1000];

	void get_value() {
		cin >> sub[ndx];
		ndx++;
	}
};

int flag = 0;

nodes node[1000];

void preorder_search(stack * stack, int idx, int dest_value) {

	if (flag == 1) {
		return;
	} // 이미 찾아버렸으면 바로 종료

	if (node[idx].ndx == 0) {
		if (idx == dest_value) {
			stack->push(idx); // 공통조상찾기와 다른 중요한점 : 자신도 포함해야 한다, 같은서브 트리 내임을 고려
			flag = 1;
		}
		return;
	}
	else {
		if (idx == dest_value) {
			stack->push(idx); // 공통조상찾기와 다른 중요한점 : 자신도 포함해야 한다, 같은서브 트리 내임을 고려
			flag = 1;
			return;
		}
		else {
			stack->push(idx);
			//cout << stack->top() << " ";
			for (int s = 0; s <= node[idx].ndx - 1; s++) {
				preorder_search(stack, node[idx].sub[s], dest_value);
			}
		}
		if (flag == 0) {
			stack->pop();
		}
	}
}

int counter_final = 0;
void pre_count_search(int idx, int dest_value, int count) {

	if (idx == dest_value) {
		flag = 1;
		counter_final = count;
		return;
	} // 이미 찾아버렸으면 바로 종료
	else {
		if (flag == 1) {
			return;
		}
		if (node[idx].ndx == 0) {
			return;
		}
		else {
			for (int s = 0; s <= node[idx].ndx - 1; s++) {
				pre_count_search(node[idx].sub[s], dest_value, count + 1);
			}
		}
	}
}


int main() {
	int total_nodes;
	cin >> total_nodes;
	int root_node = 0;
	int X;
	cin >> X;
	int Y;
	cin >> Y;

	if (X == Y) {
		cout << 0 << endl;
		return 0;
	}

	int cnt = 1;
	while (cnt < total_nodes) {
		int idx;
		cin >> idx;
		node[idx].get_value();
		cnt++;
	} // 데이터값 수령에 문제가 전혀 없음
	//cout << "clear1" << endl;

	stack_X.create(total_nodes);
	stack_Y.create(total_nodes);

	preorder_search(&stack_X, root_node, X);
	//cout << "clean" << endl;
	flag = 0; // 정말 중요

	preorder_search(&stack_Y, root_node, Y);
	//cout << "clean" << endl;
	flag = 0; // 정말 중요

	//cout << "ssipal1: " << stack_X.how_many << endl;
	//cout << "ssipal2: " << stack_Y.how_many << endl;

	int stack_Y_arr[1000];
	int temp = stack_Y.how_many;
	for (int s = 0; s < temp; s++) {
		stack_Y_arr[s] = stack_Y.top();
		stack_Y.pop();
	} quick_sort(stack_Y_arr, 0, temp - 1);

	//for (int s = 0; s < temp; s++) {
	//	cout << stack_Y_arr[s] << ' ';
	//} cout << endl;

	//cout << "clear2" << endl;

	int same_root = 0;
	while (stack_X.how_many != 0) {
		if (stack_X.top() == binary_search(stack_Y_arr, 0, temp - 1, stack_X.top())) {
			same_root = stack_X.top(); break;
		}
		stack_X.pop();
	}

	//cout << "clear3" << endl;

	pre_count_search(same_root, X, 0);
	int X_long = counter_final;
	counter_final = 0;
	flag = 0;
	pre_count_search(same_root, Y, 0);
	int Y_long = counter_final;
	counter_final = 0;
	flag = 0;

	cout << X_long + Y_long << endl;
}