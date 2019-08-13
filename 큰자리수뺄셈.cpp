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
		//cout << sen1[s];
	}

	int memorizer = 0;
	for (int s = 0; s <= LEN; s++) {
		if (sen2[s] == NULL) {
			sen2[s + 1] = NULL;
			sen2[s] = 10;
			break;
		}
		//cout << sen2[s];
	}
	//cout << endl;


	  // 각 문장별 끝 NULL idx 찾기

	for (int s = 0; s <= LEN; s++) {
		if (sen1[s] == NULL) {
			idx1 = s;
			idx1 -= 2;
			break;
		}
	}



	for (int s = 0; s <= LEN; s++) {
		if (sen2[s] == NULL) {
			idx2 = s;
			idx2 -= 2;
			break;
		}
	}

	// 1차 정렬
	int difference = abs(idx1 - idx2);

	if (idx1 > idx2) {
		for (int s = idx2; s >= 0; s--) {
			sen2[s + difference] = sen2[s];
		}
		sen2[idx1 + 1] = 10;
		sen2[idx1 + 2] = NULL;
		for (int s = 0; s <= difference - 1; s++) {
			sen2[s] = '0';
		}
	}
	else if (idx1 < idx2) {
		for (int s = idx1; s >= 0; s--) {
			sen1[s + difference] = sen1[s];
		}
		sen1[idx2 + 1] = 10;
		sen1[idx2 + 2] = NULL;
		for (int s = 0; s <= difference - 1; s++) {
			sen1[s] = '0';
		}
	}

	// 확인
	for (int s = 0; s <= LEN; s++) {
		if (sen1[s] == NULL) {
			break;
		}
		//		cout << sen1[s];
	}

	for (int s = 0; s <= LEN; s++) {
		if (sen2[s] == NULL) {

			break;
		}
		//	cout << sen2[s];
	}
	//	cout << endl;
	//  이상없음 <-
	if (strcmp(sen1, sen2) == 0) { cout << 0; }
	else if (strcmp(sen1, sen2) > 0) {
		for (int s = idx1; s >= 0; s--) {
			if (sen1[s] >= sen2[s]) {
				sum[s] += (sen1[s] - sen2[s]) + 48;
				//   cout << "hi" << (int)sum[s] << endl;
			}
			else if (sen2[s] > sen1[s]) {
				sum[s] += (sen1[s] - sen2[s] + 10) + 48;
				sum[s - 1] -= 1;
				//     cout << "hi" << (int)sum[s] << endl;
			}
		}
	}
	else {
		for (int s = idx2; s >= 0; s--) {
			if (sen2[s] >= sen1[s]) {
				sum[s + 1] += (sen2[s] - sen1[s]) + 48;
				//   cout << "bye" << (int)sum[s] << endl;
			}
			else if (sen2[s] < sen1[s]) {
				sum[s + 1] += (sen2[s] - sen1[s] + 10) + 48;
				sum[s] -= 1;
				//  cout << "bye" << (int)sum[s] << endl;
			}
		}
		sum[0] = '-';
	}

	for (int s = LEN + 1; s >= 1; s--) {
		if (sum[s] == '/') {
			sum[s] = 9 + 48;
			sum[s - 1] -= 1;
		}
	}

	for (int s = 0; s <= LEN; s++) {
		if (s == 0 && sum[s] == 48) { continue; }
		if (sum[s - 1] == '-' && sum[s] == 48) { continue; }
		if (sum[s] == NULL) {
			break;
		}
		cout << sum[s];
	}
}