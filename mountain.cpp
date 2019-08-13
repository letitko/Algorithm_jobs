#include <iostream>
using namespace std;

void fract_num(int n) {
	if (n == 0) {
		return;
	}
	fract_num(n - 1);
	cout << n;
	fract_num(n - 1);
}

int main() {

	int fract;
	cin >> fract;
	fract_num(fract);
}