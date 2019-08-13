#include <iostream>
using namespace std;
#define LEN 1000000

int num[LEN];
int temp[LEN];

int main() {
	int total_num;
	cin >> total_num;

	for (int s = 0; s < total_num; s++) {
		cin >> num[s];
	}

	temp[0] = num[0];

	for (int s = 1; s < total_num; s++) {
		if (num[s] >= num[s] + temp[s - 1]) { temp[s] = num[s]; }
		else { temp[s] = num[s] + temp[s - 1]; }
	}

	int max_num = -5818283858;

	for (int s = 0; s < total_num; s++) {
		if (temp[s] > max_num) {
			max_num = temp[s];
		}
	}

	cout << max_num << endl;
	return 0;
}