#include <iostream>
#include <string.h>
using namespace std;

// ��� N�� ���Ͽ� N�� ������ִ� �ּ� ���������� �� ������ T(N)�̶���Ѵٸ�
// T(N) = T(N-x^2)+1�� ���迡 �ִ�.

int num[100000 + 1] = { 0, };
int n;

int main() {
	memset(num, 789789789, sizeof(num));

	cin >> n;

	num[0] = 0;
	num[1] = 1;
	num[2] = 2;
	num[3] = 3;
	for (int s = 4; s <= 100000; s++) {

		int nums = 1;
		while (nums*nums <= s) {
			nums += 1;
		}
		nums -= 1;
		for (int t = nums; t >= 1; t--) {
			if (num[s - t * t] + 1 < num[s]) {
				num[s] = num[s - t * t] + 1;
			}
		}
	}

	cout << num[n];
}