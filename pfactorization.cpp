#include <iostream>
using namespace std;

int main() {
	long long int num;
	cin >> num;

	for (int s = 2; s <= num; s++) {
		while (num%s == 0) {
			cout << s << endl;
			num /= s;
		}
	}
}