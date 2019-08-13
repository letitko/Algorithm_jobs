#include <iostream>
#include <string.h>
using namespace std;
#define LEN 1000

char sen1[LEN + 1];
char sen2[LEN + 1];
char sum[LEN + 1];

int main() {
	memset(sum, NULL, sizeof(sum));
	memset(sen1, NULL, sizeof(sum));
	memset(sen2, NULL, sizeof(sum));

	fgets(sen1, sizeof(sen1), stdin);
	fgets(sen2, sizeof(sen2), stdin);

	int idx1 = 0;
	int idx2 = 0;

	while (sen1[idx1] != NULL) { // 데이터의 숫자 끝자락 찾기
		//cout << sen1[idx1];
		sen1[idx1] %= 48;
		idx1++;
	} idx1 -= 2;
	sen1[idx1 + 1] = NULL;

	while (sen2[idx2] != NULL) { // 데이터의 숫자 끝자락 찾기
		//cout << sen2[idx2];
		sen2[idx2] %= 48;
		idx2++;
	} idx2 -= 1; // 온라인 컴파일러 -1로 표기바람, VS는 -2로
	sen2[idx2 + 1] = NULL;
	// cout << endl; // 온라인 컴파일러 살리기 바람

	//cout << idx1 << endl;
	//cout << idx2 << endl;

	int flag = -1;
	if (idx1 > idx2) {
		flag = 1;
	}
	else if (idx2 > idx1) {
		flag = 0;
	}
	else {
		//cout << strcmp(sen1, sen2);
		if (strcmp(sen1, sen2) <= 0) {
			flag = 0;
		}
		else {
			flag = 1;
		}
	}


	int temp_idx_1 = 1000;
	int temp_idx_2 = 1000;

	for (int s = idx1; s >= 0; s--) { // 데이터를 배열 뒷부분으로 옮기기
		sen1[temp_idx_1] = sen1[s];
		temp_idx_1--;
	} temp_idx_1 += 1; // temp_idx_1은 숫자의 시작점을 알림***

	//for (int s = temp_idx_1; s <= 1000; s++) {
	//	cout << (int)sen1[s];
	//} cout << endl;

	for (int s = 0; s <= idx1 + 2; s++) { // 옮기고 남은 원래 부분 초기화
		sen1[s] = NULL;
	}

	for (int s = idx2; s >= 0; s--) { // 데이터를 배열 뒷부분으로 옮기기
		sen2[temp_idx_2] = sen2[s];
		temp_idx_2--;
	} temp_idx_2 += 1; // temp_idx_2은 숫자의 시작점을 알림***

	//for (int s = temp_idx_2; s <= 1000; s++) {
	//	cout << (int)sen2[s];
	//} cout << endl;


	for (int s = 0; s <= idx2 + 2; s++) { // 옮기고 남은 원래 부분 초기화
		sen2[s] = NULL;
	}
	//cout << "flag : " << flag << endl;

	int how_long;

	if (flag == 1) {
		for (int start_idx = 1000; start_idx >= temp_idx_2; start_idx--) {
			int save_idx = start_idx;
			for (int op = 1000; op >= temp_idx_1; op--) {

				if (sum[save_idx] >= 10) {
					sum[save_idx - 1] += sum[save_idx] / 10;
					sum[save_idx] %= 10;
				}

				if (sum[save_idx - 1] >= 10) {
					sum[save_idx - 2] += sum[save_idx - 1] / 10;
					sum[save_idx - 1] %= 10;
				}

				if ((sen1[op] * sen2[start_idx] >= 10)) {
					sum[save_idx - 1] += (sen1[op] * sen2[start_idx]) / 10;
					sum[save_idx] += (sen1[op] * sen2[start_idx]) % 10;
					save_idx -= 1;
				}
				else {
					sum[save_idx] += sen1[op] * sen2[start_idx];
					save_idx -= 1;
				}

				if (sum[save_idx + 1] >= 10) {
					sum[save_idx] += sum[save_idx + 1] / 10;
					sum[save_idx + 1] %= 10;
				}


			}
			if (start_idx == temp_idx_2) {
				how_long = save_idx; // how_long은 마지막 수가 저장된 곳을 바라본다
			}
		}

		for (int start_idx = 1000; start_idx >= how_long - 1; start_idx--) { // 아스키코드 정렬
			sum[start_idx] += 48; // 문제발생시 참고
		}


		while (sum[how_long] == '0' || sum[how_long] == NULL || sum[how_long] == '10') {
			how_long++;
		}

		for (int start_idx = how_long; start_idx <= 1000; start_idx++) { // 값 출력
			cout << sum[start_idx];
		}

	}
	else {
		for (int start_idx = 1000; start_idx >= temp_idx_1; start_idx--) {
			int save_idx = start_idx;
			for (int op = 1000; op >= temp_idx_2; op--) {

				if (sum[save_idx] >= 10) {
					sum[save_idx - 1] += sum[save_idx] / 10;
					sum[save_idx] %= 10;
				}

				if (sum[save_idx - 1] >= 10) {
					sum[save_idx - 2] += sum[save_idx - 1] / 10;
					sum[save_idx - 1] %= 10;
				}

				if ((sen2[op] * sen1[start_idx] >= 10)) {
					sum[save_idx - 1] += (sen2[op] * sen1[start_idx]) / 10;
					sum[save_idx] += (sen2[op] * sen1[start_idx]) % 10;
					save_idx -= 1;
				}
				else {
					sum[save_idx] += sen2[op] * sen1[start_idx];
					save_idx -= 1;
				}

				if (sum[save_idx + 1] >= 10) {
					sum[save_idx] += sum[save_idx + 1] / 10;
					sum[save_idx + 1] %= 10;
				}


			}
			if (start_idx == temp_idx_1) {
				how_long = save_idx; // how_long은 마지막 수가 저장된 곳을 바라본다
			}
		}

		for (int start_idx = 1000; start_idx >= how_long - 1; start_idx--) { // 아스키코드 정렬
			sum[start_idx] += 48; // 문제발생시 참고
		}

		while (sum[how_long] == '0' || sum[how_long] == NULL || sum[how_long] == '10') {
			how_long++;
		}

		for (int start_idx = how_long; start_idx <= 1000; start_idx++) { // 값 출력
			cout << sum[start_idx];
		}

	}
}