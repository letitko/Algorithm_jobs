#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
int idx = 0;
int house[625];

bool possibility[26][26];
char arr[26][26];

void part_time(int x, int y) {
	possibility[x][y] = true;
	house[idx] += 1;

	// 깊이 우선 실행
	if (possibility[x + 1][y] == false && arr[x + 1][y] == '1' && x + 1 <= n - 1) {
		part_time(x + 1, y);
	} // 선 하단
	if (possibility[x - 1][y] == false && arr[x - 1][y] == '1' && x - 1 >= 0) {
		part_time(x - 1, y);
	} // 선 상단

	// 너비 실행
	if (possibility[x][y - 1] == false && arr[x][y - 1] == '1' && y - 1 >= 0) {
		part_time(x, y - 1);
	} // 좌
	if (possibility[x][y + 1] == false && arr[x][y + 1] == '1' && y + 1 <= n - 1) {
		part_time(x, y + 1);
	} // 우

	return;
}

int main() {
	cin >> n;
	for (int s = 0; s < n; s++) {
		cin >> arr[s];
	}

	/*for (int s = 0; s < n; s++) {
		for (int t = 0; t < n; t++) {
			cout << arr[s][t];
		}
		cout << endl;
	}*/

	for (int s = 0; s < n; s++) {
		for (int t = 0; t < n; t++) {
			if (possibility[s][t] == false && arr[s][t] == '1') {
				part_time(s, t);
				idx += 1;
			}
		}
	}
	sort(house, house + idx);
	cout << idx << endl;
	for (int s = 0; s < idx; s++) {
		cout << house[s] << endl;
	}

	return 0;
}