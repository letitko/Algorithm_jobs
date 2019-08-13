#include <iostream>
#define HELLCOW 15
using namespace std;

int set_up(int *cow, int *new_cow, char *temp_mos, int total_cow) {

	int cow_idx = 1;
	int ncow_idx = 1;

	new_cow[0] = 1;
	for (int s = 0; s <= total_cow - 2; s++) {
		if (temp_mos[s] == '+' || temp_mos[s] == '-') {
			new_cow[ncow_idx] = cow[cow_idx];
			cow_idx++;
			ncow_idx++;
		}
		else {
			if (cow[cow_idx] >= 10) {
				new_cow[ncow_idx - 1] = new_cow[ncow_idx - 1] * 100 + cow[cow_idx];
			}
			else {
				new_cow[ncow_idx - 1] = new_cow[ncow_idx - 1] * 10 + cow[cow_idx];
			}
			cow_idx++;
		}
		if (s == total_cow - 2) {
			new_cow[ncow_idx] = cow[cow_idx];
		}
	}

	//int temp_idx = 0;
	//while (new_cow[temp_idx] != NULL) {
	//	cout << new_cow[temp_idx] << ' ';
	//		temp_idx++;
	//	} cout << endl;

	int sum_idx = 1;
	int sum = 0;
	sum = new_cow[0];
	for (int s = 0; s <= total_cow - 2; s++) {
		if (temp_mos[s] == '+') {
			sum += new_cow[sum_idx];
			sum_idx++;
		}
		else if (temp_mos[s] == '-') {
			sum -= new_cow[sum_idx];
			sum_idx++;
		}
	}

	return sum;
}

int cal(int op, int num1, int num2) {
	if (op == '+') { //43
		return num1 + num2;
	}
	else if (op == '-') { //45
		return num1 - num2;
	}
}

void get_mos_cow(int *new_cow, int* cow, char *mos, char *temp_mos, int total_cow, int idx, int *count) {

	if (idx == total_cow - 1) {

		/*
		// 부호확인
		for (int s = 0; s <= total_cow - 2; s++) {
			cout << temp_mos[s];
		}
		cout << endl;
		*/

		if (set_up(cow, new_cow, temp_mos, total_cow) == 0) {

			if (*count < 20) {
				for (int s = 0; s <= total_cow - 1; s++) {
					cout << cow[s] << ' ';
					if (s == total_cow - 1) { continue; }
					cout << temp_mos[s] << ' ';
				}
				cout << endl;
			}
			*count += 1;
		}

		return;
	} // 탈출조건

	for (int s = 0; s < 3; s++) {
		temp_mos[idx] = mos[s];
		get_mos_cow(new_cow, cow, mos, temp_mos, total_cow, idx + 1, count);
	} // 부호 받아두기 <- 아주 잘됨 temp_mos에 저장됨
}

int main() {

	//char money[5] = "1234";
	//char money2[5] = "5678";
	//int bigger = (atoi(money) >= atoi(money2) ? 1 : 2);
	//int op = 0;
	//cout << atoi(money);
	//cout << bigger; == 결과 2 출력


	int cow[HELLCOW];
	int new_cow[HELLCOW];

	for (int s = 0; s < HELLCOW; s++) {
		new_cow[s] = NULL;
	}


	char mos[3] = { '+','-','.' }; // mos의 주소 0부터 시작
	char temp_mos[HELLCOW - 1]; // temp의 주소 -> 0부터 시작

	for (int s = 0; s <= HELLCOW - 1; s++) {
		cow[s] = s + 1;
	}

	int cow_num = 0;
	cin >> cow_num;


	int idx = 0;
	int count = 0;
	get_mos_cow(new_cow, cow, mos, temp_mos, cow_num, idx, &count);
	cout << count;
}

/*
++++
+++-
+++.
++-+
++--
++-.
.
.
.
....
*/