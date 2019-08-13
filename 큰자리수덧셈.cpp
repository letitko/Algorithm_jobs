#include <iostream>
#include <string.h>
using namespace std;
#define LEN 1000

int main() {
	char sen1[LEN + 1];
	char sen2[LEN + 1];
	char sum[LEN + 2] = { '\0', };
	memset(sum, NULL, sizeof(sum));

	int idx1;
	int idx2;

	fgets(sen1, sizeof(sen1), stdin);
	fgets(sen2, sizeof(sen2), stdin);

	// 확인

	for (int s = 0; s <= LEN; s++) {
		if (sen1[s] == NULL) {
			break;
		}
		//	cout << sen1[s];
	}

	int memorizer = 0;
	for (int s = 0; s <= LEN; s++) {
		if (sen2[s] == NULL) {
			sen2[s + 1] = NULL;
			sen2[s] = 10;
			break;
		}
		//	cout << sen2[s];
	}
	//  cout << endl;


	// 각 문장별 끝 NULL idx 찾기

	for (int s = 0; s <= LEN; s++) {
		if (sen1[s] == NULL) {
			idx1 = s;
			break;
		}
	}
	for (int s = 0; s <= LEN; s++) {
		if (sen2[s] == NULL) {
			idx2 = s;
			break;
		}
	}


	// 1차 정렬

	int difference = (idx1 >= idx2 ? idx1 - idx2 : abs(idx1 - idx2));

	if (idx1 >= idx2) {
		for (int s = idx2 - 1; s >= 0; s--) {
			sen2[difference + s] = sen2[s];
		}
		sen2[difference + idx2] = NULL;
		memset(sen2, '0', difference);
	}
	else {
		for (int s = idx1 - 1; s >= 0; s--) {
			sen1[difference + s] = sen1[s];
		}
		sen1[difference + idx1] = NULL;
		memset(sen1, '0', difference);
	}

	// 확인
	//	for (int s = 0; s <= LEN; s++) {
	//		if (sen1[s] == NULL) {
	//			break;
	//		}
	//		cout << sen1[s];
	//	}
	//
	//	for (int s = 0; s <= LEN; s++) {
	//		if (sen2[s] == NULL) {
	//			break;
	//		}
	//		cout << sen2[s];
	//	}
	//		cout << endl;
	// 이상없음 <-

	//	cout << endl;
	int bigger = (idx1 >= idx2 ? idx1 : idx2);
	//	cout << bigger << endl;
	//	cout << difference << endl;

	// 덧셈 인덱스
	if (idx1 >= idx2) {
		for (int s = bigger - 2; s >= difference; s--) {
			sum[s + 1] = 48 + (sen1[s] % 48) + (sen2[s] % 48);
		}
		for (int s = difference - 1; s >= 0; s--) {
			sum[s + 1] = 48 + (sen1[s] % 48);
		}
	}
	else {
		for (int s = bigger - 2; s >= difference; s--) {
			sum[s + 1] = 48 + (sen1[s] % 48) + (sen2[s] % 48);
		}
		for (int s = difference - 1; s >= 0; s--) {
			sum[s + 1] = 48 + (sen2[s] % 48);
		}
	}

	// 올림수 정리
	for (int s = bigger - 1; s > 0; s--) {
		if (sum[s] >= 58) {
			if (s == 1) {
				sum[1] -= 10;
				sum[0] = '1';
				continue;
			}
			sum[s] -= 10;
			sum[s - 1] += 1;
		}
	}

	for (int s = 0; s <= bigger - 1; s++) {
		if (sum[s] == NULL) { continue; }
		cout << sum[s];
	}
}