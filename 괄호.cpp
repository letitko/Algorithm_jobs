#include <iostream>
using namespace std;

class stack {
public:
	char data[51]; // 데이터량
	int how_many = 0; // 원소개수
	int size = 0; // 최대수용개수

	void create(int s) { // 최대수용수한정
		size = s;
	}

	void push(char insert_data) {
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

	stack s;
	s.create(50);

	char sample[51];
	int total_num;
	fgets(sample, sizeof(sample), stdin);
	for (int s = 0; s <= 50; s++) {
		if (sample[s] == NULL) {
			total_num = s; // 현재 보관된 원소의 총 개수 파악
			break;
		}
	}

	int flag = 0;
	for (int t = 0; t < total_num; t++) {
		if (sample[t] == '(') {
			s.push('(');
		}
		else if (sample[t] == ')' && s.how_many == 0) { flag = 1; break; }
		else if (sample[t] == ')' && s.how_many != 0) { s.pop(); }
		else { break; }
	}

	if (s.how_many == 0 && flag == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}