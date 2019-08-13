#include <iostream>
using namespace std;
#define LEN


void combi(int n, int m) {
	long long int counter = m;
	long long int num = 1;
	long long int ccu = 1;

	while (counter != 0) {

		num *= n;
	//	cout << num << ": 1 연산" << endl;
		num /= ccu;
	//	cout << num << ": 2 연산" << endl;

		n--;
		ccu++;
		counter--;
	}

	cout << (int)num;
}

int main() {

	int  n, m;
	cin >> n >> m;

	combi(n, m);
}