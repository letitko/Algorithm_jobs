#include <iostream>
#include <string.h>
#define LEN 10 // 연산자개수 2~9
#define TRUE 1
#define FALSE 0
using namespace std;

/*
class master {
public:
	char biggest[LEN + 1];
	char
};
*/

bool is_right(char op, int num1, int num2) {
	if (op == '>') {
		if (num1 > num2) {
			return TRUE;
		}
		else { return FALSE; }
	}
	else {
		if (num1 < num2) {
			return TRUE;
		}
		else { return FALSE; }
	}
}

void inequal(int *num, char *op, int idx, int total_op, int *count) {

	if (*count == 1) {
		return;
	}

	for (int t = 0; t <= idx - 2; t++) {
		if (is_right(op[t], num[t], num[t + 1]) == 0) {
			return; // 가지치기2
		}
	}

	if (idx == total_op + 1) { // 기저조건
		for (int s = 0; s <= total_op; s++) {
			cout << num[s];
			//if (s == total_op) { continue; }
			//cout << op[s];
		}
		cout << endl;
		*count += 1;
		return;
	}

	for (int s = 9; s >= 0; s--) {

		int is_possible = 0;

		if (idx != 0) {
			for (int t = 0; t <= idx - 1; t++) {
				if (num[t] == s) { is_possible = 1; break; } // 가지치기1
			}
		}

		if (is_possible == 0) {
			num[idx] = s;
			inequal(num, op, idx + 1, total_op, count);
		}
	}
}

void unequal(int *num, char *op, int idx, int total_op, int *count) {

	if (*count == 1) {
		return;
	}

	for (int t = 0; t <= idx - 2; t++) {
		if (is_right(op[t], num[t], num[t + 1]) == 0) {
			return; // 가지치기2
		}
	}

	if (idx == total_op + 1) { // 기저조건
		for (int s = 0; s <= total_op; s++) {
			cout << num[s];
			//if (s == total_op) { continue; }
			//cout << op[s];
		}
		cout << endl;
		*count += 1;
		return;
	}

	for (int s = 0; s <= 9; s++) {

		int is_possible = 0;

		if (idx != 0) {
			for (int t = 0; t <= idx - 1; t++) {
				if (num[t] == s) { is_possible = 1; break; } // 가지치기1
			}
		}

		if (is_possible == 0) {
			num[idx] = s;
			unequal(num, op, idx + 1, total_op, count);
		}
	}
}

int main() {

	int num[LEN + 1];
	memset(num, NULL, sizeof(num));

	int num2[LEN + 1];
	memset(num, NULL, sizeof(num));

	char op[LEN];
	memset(op, NULL, sizeof(op));

	int total_op = 0;
	cin >> total_op;

	int count_s = 0;
	int count_m = 0;

	for (int s = 0; s <= total_op - 1; s++) {
		cin >> op[s];
	}

	inequal(num, op, 0, total_op, &count_s);
	unequal(num2, op, 0, total_op, &count_m);
}