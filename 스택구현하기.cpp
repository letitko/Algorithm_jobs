#include <iostream>
using namespace std;

class operators {
public:
	int main;
	int sub;
};

class stack {
public:
	int data[101]; // 데이터량
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

int main() {

	int size_of_stack;
	int times_of_operating;
	static operators op[1000];

	cin >> size_of_stack;
	cin >> times_of_operating;

	for (int idx = 0; idx < times_of_operating; idx++) {
		int is;
		cin >> is;
		if (is != 1) {
			op[idx].main = is;
		}
		else {
			op[idx].main = is;
			cin >> op[idx].sub;
		}
	}

	/*
	for (int idx = 0; idx < times_of_operating; idx++) {
		int is;
		is = op[idx].main;
		if (is != 1) {
			cout << op[idx].main << endl;
		}
		else {
			cout << op[idx].main << ' ' << op[idx].sub << endl;
		}
	}
	*/


	stack s1;
	s1.create(size_of_stack);

	//push = 1;
	//pop = 2;
	//top = 3;

	for (int idx = 0; idx < times_of_operating; idx++) {
		if (op[idx].main == 2) {
			s1.pop();
		}
		else if (op[idx].main == 3) {
			int backup = s1.top();
			if (backup != -1) {
				cout << backup << endl;
			}
			else {
				cout << "NULL" << endl;
			}
		}
		else {
			s1.push(op[idx].sub);
		}
	}

	return 0;
}