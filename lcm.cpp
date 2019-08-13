#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b) {
	// �ִ� �����
	while (b != 0) {
		long long int	r = a%b;
		a = b;
		b = r;
	}
	return a;
}

long long int lcm(long long int a, long long int b) {
	// �ּ� �����
	return (a / gcd(a, b)) * (b / gcd(a, b)) * gcd(a, b);
}

int main() {

	long long int a;
	long long int b;
	cin >> a >> b;
	cout << lcm(a, b);
}