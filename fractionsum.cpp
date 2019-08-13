#include <iostream>
using namespace std;
#define LEN 7

int main() {
	int num1_top;
	int num1_bot;
	int num2_top;
	int num2_bot;

	cin >> num1_top;
	cin >> num1_bot;
	cin >> num2_top;
	cin >> num2_bot;

	int sum_top = num1_top*num2_bot+num2_top*num1_bot;
	int sum_bot = num2_bot*num1_bot;


	int result = (sum_top >= sum_bot ? sum_bot : sum_top);

	for (int s = 2; s <= result; s++) {
		while (sum_top % s == 0 && sum_bot % s == 0) {
			sum_top /= s;
			sum_bot /= s;
		}
	}

	cout << sum_top << " " << sum_bot << endl;
}