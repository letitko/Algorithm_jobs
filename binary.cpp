#include <iostream>
#define LEN 10
using namespace std;

void bin(int n) {
	if (n == 1)
	{
		cout << 1;
		return;
	}
	bin(n/2);
	cout << n%2;
}

int main() {
	int lenth[LEN + 1] = { };
	int n;
	cin >> n;
	bin(n);
}