#include <iostream>
#include <string.h>
using namespace std;

class stack {
public:
	char data[32]; // 데이터량
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
	char sample[32];
	memset(sample, NULL, sizeof(sample));
	fgets(sample, sizeof(sample), stdin);

	int idx = 0;
	while (1) {
		if (sample[idx] == NULL) {
			break;
		}
		idx++;
	} idx -= 1; // idx 변동

	// cout << idx << endl;

	if (idx % 2 == 0) { cout << '0' << endl; return 0; }

	stack op;
	op.create(32);
	int is_error = 0;

	for (int s = 0; s <= idx; s++) { // 데이터 정상 여부부터 확인
		if (op.how_many <= 0) { // 데이터가 하나도 없을때
			if (sample[s] == ')' || sample[s] == ']') {
				//cout << "error_1" << endl;
				is_error = 1;
				break;
			}
			else {
				op.push(sample[s]);
			}
		}
		else { // 데이터가 하나라도 존재할때
			if (sample[s] == ')') {
				if (op.top() == '(') {
					op.pop();
				}
				else {
					//cout << "error_2" << endl;
					is_error = 1;
					break;
				}
			}
			else if (sample[s] == ']') {
				if (op.top() == '[') {
					op.pop();
				}
				else {
					//cout << "error_3" << endl;
					is_error = 1;
					break;
				}
			}
			else {
				op.push(sample[s]);
			}
		}

	}

	if (is_error == 1) {
		cout << "0" << endl;
	}
	else {
		int temp = 1;
		int result = 0;
		int turn_on = 0;
		for (int s = 0; s <= idx; s++) {
			if (sample[s] == '(') {
				op.push(sample[s]);
				temp *= 2;
				turn_on = 1;
			}
			else if (sample[s] == '[') {
				op.push(sample[s]);
				temp *= 3;
				turn_on = 1;
			}
			else if (sample[s] == ')') {
				op.pop();
				if (turn_on == 1) {
					result += temp;
					turn_on = 0;
				}
				temp /= 2;
			}
			else {
				op.pop();
				if (turn_on == 1) {
					result += temp;
					turn_on = 0;
				}
				temp /= 3;
			}
			// cout << "process : " << s << result << endl;
		}
		cout << result;
	}
}