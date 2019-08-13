#include <iostream>
#define LEN 999
#define REAL_LEN 987
using namespace std;

class qna {
public:
	int data[3 + 1];
	int strike = 0;
	int ball = 0;
};

class num {
public:
	int data[3 + 1];
	int ok = 0; // 후보가 될 수 있는 녀석들만 찾아내면 됨
};

int main() {

	num nums[LEN + 1]; // 숫자 후보 선언

	// 각 후보 데이터 초기화
	for (int s = 1; s <= 9; s++) {
		for (int t = 1; t <= 9; t++) {
			if (s == t) { continue; }
			for (int u = 1; u <= 9; u++) {
				if (s == u || t == u) { continue; }
				else {
					nums[s * 100 + t * 10 + u * 1].data[1] = s;
					nums[s * 100 + t * 10 + u * 1].data[2] = t;
					nums[s * 100 + t * 10 + u * 1].data[3] = u;
				}
			}
		}
	}

	int total_q = 0;
	cin >> total_q;
	qna q_list[100 + 1];

	// 문제 입력
	for (int s = 1; s <= total_q; s++) {
		int extra;
		cin >> extra;
		q_list[s].data[1] = extra / 100;
		q_list[s].data[2] = (extra % 100) / 10;
		q_list[s].data[3] = extra % 10;
		cin >> q_list[s].strike;
		cin >> q_list[s].ball;
	}

	// 문제 입력 확인
	/*
	for (int s = 1; s <= total_q; s++) {

		cout << q_list[s].data[1];
		cout << q_list[s].data[2];
		cout << q_list[s].data[3];
		cout << " ";
		cout << q_list[s].strike;
		cout << " ";
		cout << q_list[s].ball;
		cout << endl;
	}
	*/

	// 비교해서 후보 선발
	for (int k = 1; k <= total_q; k++) {
		for (int s = 1; s <= 9; s++) {
			for (int t = 1; t <= 9; t++) {
				if (s == t) { continue; }
				for (int u = 1; u <= 9; u++) {
					if (u == s || u == t) { continue; }
					else {
						int strike = 0;
						int ball = 0;
						if (s == q_list[k].data[1]) {
							strike++;
						}
						if (t == q_list[k].data[2]) {
							strike++;
						}
						if (u == q_list[k].data[3]) {
							strike++;
						}
						if (s == q_list[k].data[2] || s == q_list[k].data[3]) {
							ball++;
						}
						if (t == q_list[k].data[1] || t == q_list[k].data[3]) {
							ball++;
						}
						if (u == q_list[k].data[1] || u == q_list[k].data[2]) {
							ball++;
						}
						if (strike == q_list[k].strike && ball == q_list[k].ball) {
							nums[s * 100 + t * 10 + u * 1].ok++;
						}
					}
				}
			}
		}
	}

	int	f_counter = 0;
	for (int s = 1; s <= 9; s++) {
		for (int t = 1; t <= 9; t++) {
			if (t == s) { continue; }
			for (int u = 1; u <= 9; u++) {
				if (u == s || u == t) { continue; }
				else if (nums[s * 100 + t * 10 + u * 1].ok == total_q) {
					f_counter++;
					//cout << "실행 ";
				}
			}
		}
	}

	cout << f_counter;
}