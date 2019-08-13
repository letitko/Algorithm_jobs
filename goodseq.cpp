#include <iostream>
#include <string.h>
#include <stdlib.h>
#define LEN 81
using namespace std;

int arr[LEN];
char temp_arr[LEN / 2 + 1];
char temp_arr2[LEN / 2 + 1];

int flag = 0;

bool control(int idx) {

	int is_cnt = 0;
	for (int s = idx - 1; s >= idx / 2; s--) {
		int idx_1 = 0;
		int idx_2 = 0;
		for (int t = 0; t <= is_cnt; t++) {
			temp_arr[idx_1] = (char)arr[idx - t];
			temp_arr2[idx_2] = (char)arr[s - t];
			idx_1++;
			idx_2++;
		}
		//for (int t = 0; t < idx_1; t++) {
	//		cout << (int)temp_arr[t];
	//	} //cout << "end1" << endl;

	//	for (int t = 0; t < idx_2; t++) {
	//		cout << (int)temp_arr2[t];
	//	} //cout << "end2" << endl;

		if (strcmp(temp_arr, temp_arr2) == 0) {
			//cout << "¹ßµ¿";
			return 0;
		}
		else {
			memset(temp_arr, NULL, sizeof(temp_arr));
			memset(temp_arr2, NULL, sizeof(temp_arr2));
		}
		is_cnt++;
	}
	return 1;
}

void num_recursion(int total_num, int now_num, int idx) {
	if (flag == 1) { return; }
	if (total_num == now_num) {
		for (int s = 0; s < total_num; s++) {
			cout << arr[s];
		} cout << endl;
		flag = 1;
		return;
	}

	for (int s = 1; s <= 3; s++) {
		arr[idx] = s;
		//cout << "value" << ":" << s << " " << "idx" << ":" << idx << " " << "bool:" << (control(idx)) << ' ' << endl;
		if (control(idx) == 1) {
			num_recursion(total_num, now_num + 1, idx + 1);
		}
	}
	return;
}

int main() {
	memset(temp_arr, NULL, sizeof(temp_arr));
	memset(temp_arr2, NULL, sizeof(temp_arr2));
	arr[0] = 1;
	int total_num;
	cin >> total_num;
	num_recursion(total_num, 1, 1);
}