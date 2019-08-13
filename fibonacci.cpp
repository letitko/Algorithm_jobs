#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int num[46];
	num[0] = 0;
	num[1] = 1;
	for (int s = 2; s <= 45; s++) {
		num[s] = num[s - 2] + num[s - 1];
	}
	
	cout << num[n];
}