#include <iostream>
using namespace std;

int binary_search(int arr[], int start, int end, int value) {

	// ����Ž�� ����� ����
	// ***���������� ���������� �̹� ���ڵ��� ���ĵǾ��־����

	// ��������
	if (start > end) { // ���� ���Ұ� �� �ϳ��� ���� ���
		return -1;
	}
	else if (start == end) { // ���� ���Ұ� �� �ϳ��϶�, ���۰� ���� �����Ҷ�
		if (arr[start] == value) { return arr[start]; } // �������� ã�Ƴ��ٸ� ���� �����ϴ� idx��ȯ
		else { return -1; } // ��ã�� ��� -1 ��ȯ
	}

	// ��ɺ�
	int mid = (start + end) / 2; // �߰� idx�� ���ؼ�
	if (arr[mid] == value) { return arr[mid]; } // �װ��� ���ʿ� ��ġ�ϸ� ���ġ ���� �����ϴ� idx��ȯ
	else if (arr[mid] > value) { binary_search(arr, start, mid - 1, value); } // ã������ �� ���� �迭�� �߰����� �� ũ�ٸ�- ������������ �߰����� �������ȴ�
	else { binary_search(arr, mid + 1, end, value); } // ã������ �� ���� �迭�� �߰����� �� �۴ٸ�- ������������ �߰����� �������ȴ�

}


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
	static int left[1000];
	static int right[1000];

	// �ǹ����� ������ �� ���ڵ� left[LEN]�� ����ϰ� left[LEN]�� ���Ұ��� ȹ��
	int left_count = get_left(num, pivot, start, end, left); // ���⼭ ***left_cnt�� ����
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
	for (int n = 0; n <= right_count - 1; n++) {
		num[start + left_count + 1 + n] = right[n]; // num[]�� ���Խô� start�� index�������� ������ �ؾ���
	}

	quick_sort(num, start, start + left_count - 1); // ****�Լ��� ���� ���Խÿ��� start�� index�������� ������ �ؾ���
	quick_sort(num, start + left_count + 1, end); // ****�Լ��� ���� ���Խÿ��� start�� index�������� ������ �ؾ���

}

class stack {
public:
	int data[1000]; // �����ͷ�
	int how_many = 0; // ���Ұ���
	int size = 0; // �ִ���밳��

	void create(int s) { // �ִ���������
		size = s;
	}

	void push(int insert_data) {
		if (how_many >= size) {
			cout << "Overflow" << endl;
		}
		else {
			data[how_many] = insert_data; // �ε������� ������ �Է�
			how_many++; // ��������
		}
	}

	void pop() {
		if (how_many <= 0) {
			cout << "Underflow" << endl;
		}
		else {
			data[how_many - 1] = 0; // �ε������� �������ϳ� ����
			how_many--; // ��������
		}
	}

	int top() {
		// �����Ͱ� ���� ���  -1 ����
		if (how_many <= 0) {
			return -1;
		}
		else {
			return data[how_many - 1];// �ε������� ���� �ֻ��� �������ϳ� ���
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
	} // �̹� ã�ƹ������� �ٷ� ����

	if (node[idx].ndx == 0) {
		if (idx == dest_value) {
			stack->push(idx); // ��������ã��� �ٸ� �߿����� : �ڽŵ� �����ؾ� �Ѵ�, �������� Ʈ�� ������ ���
			flag = 1;
		}
		return;
	}
	else {
		if (idx == dest_value) {
			stack->push(idx); // ��������ã��� �ٸ� �߿����� : �ڽŵ� �����ؾ� �Ѵ�, �������� Ʈ�� ������ ���
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
	} // �̹� ã�ƹ������� �ٷ� ����
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
	} // �����Ͱ� ���ɿ� ������ ���� ����
	//cout << "clear1" << endl;

	stack_X.create(total_nodes);
	stack_Y.create(total_nodes);

	preorder_search(&stack_X, root_node, X);
	//cout << "clean" << endl;
	flag = 0; // ���� �߿�

	preorder_search(&stack_Y, root_node, Y);
	//cout << "clean" << endl;
	flag = 0; // ���� �߿�

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