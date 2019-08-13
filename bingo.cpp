#include <iostream>
#define LEN 5
using namespace std;

typedef class NUM {
public:
	int data = NULL;
	int count = 0;
}numeric;

void bingo(numeric *student, int teacher) {
	if (teacher == student->data) {
		student->count++;
	}
}

bool say_bingo(numeric student[LEN + 1][LEN + 1]) {

	int bingo_counter = 0;

	for (int s = 1; s <= LEN; s++) {
		int is_bingo = 0;
		for (int t = 1; t <= LEN; t++) {
			is_bingo += student[s][t].count;
		}
		if (is_bingo == 5) {
			bingo_counter += 1;
		}
	}

	for (int s = 1; s <= LEN; s++) {
		int is_bingo = 0;
		for (int t = 1; t <= LEN; t++) {
			is_bingo += student[t][s].count;
		}
		if (is_bingo == 5) {
			bingo_counter += 1;
		}
	}

	int let_bingo = 0;

	for (int s = 1; s <= LEN; s++) {
		let_bingo += student[s][s].count;
		if (let_bingo == 5) {
			bingo_counter += 1;
		}
	}

	int reverse_let_bingo = 0;

	for (int s = 5; s >= 1; s--) {
		reverse_let_bingo += student[s][6 - s].count;
		if (reverse_let_bingo == 5) {
			bingo_counter += 1;
		}
	}

	if (bingo_counter >= 3) { return 1; }
	else { return 0; }	
}

int main() {

	numeric student[LEN + 1][LEN + 1];
	int teacher[LEN + 1][LEN + 1];

	for (int s = 1; s <= LEN; s++) {
		for (int t = 1; t <= LEN; t++)
			cin >> student[s][t].data;
	}

	for (int s = 1; s <= LEN; s++) {
		for (int t = 1; t <= LEN; t++)
			cin >> teacher[s][t];
	}

	int boom = 0;
	for (int i = 1; i <= LEN; i++) {
		for (int j = 1; j <= LEN; j++) {

			for (int s = 1; s <= LEN; s++) {
				for (int t = 1; t <= LEN; t++) {
					bingo(&student[s][t], teacher[i][j]);
					if (say_bingo(student) == 1) {
						cout << (i - 1) * 5 + j ;
						boom = 1;
						break;
					}
				}
				if (boom == 1) { break; }
			}
			if (boom == 1) { break; }
		}
		if (boom == 1) { break; }
	}
}
