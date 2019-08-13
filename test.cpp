#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define LEN 12
using namespace std;

int Total_test;
int test_num;
int arr[12];

void rotate(int arr[12]) {
	
	int temp = arr[11];

	for (int s = 10; s >= 0; s--) {
		arr[s + 1] = arr[s];
	}

	arr[0] = temp;
}

// arr -> 0~2 / 3~5 / 6~8 / 9~11

int main() {
	cin >> Total_test;
	for (test_num = 1; test_num <= Total_test;test_num++) {
		cout << '#' << test_num << ' ';

		for (int s = 0; s < 12; s++) {
			cin >> hex >> arr[s];
		}




	}
	return 0;
}