#include <iostream>
using namespace std;

int main() {
	int len, n;
	cin >> len;
	 
	int equation[100 + 1];
	int nums_2[100 + 1];
	int nums[100 + 1];

	for (int s = 1; s <= len; s++) {
		cin >> equation[s];
	}

	for (int t = 1; t <= len; t++) {
		nums_2[t] = equation[t] * t;
	}

	nums[1] = nums_2[1];
	for (int t = 2; t <= len ; t++) {
		nums[t] = nums_2[t] - nums_2[t - 1];
	}
		
	for (int t = 1; t <= len; t++) {
		cout << nums[t] << " ";
	}

	cout << endl;
}