#include <iostream>
using namespace std;

int cal(int a, int b, char op) {
	if (op == '+') { return a + b; }
	else if (op == '-') { return a - b; }
	else if (op == '*') { return a	*	b; }
	else { return a / b; }
}

int main() {
	char op;
	int a;
	int b;

	cin >> a >> op >> b;
	int result = cal(a, b, op);
	cout << result;
}