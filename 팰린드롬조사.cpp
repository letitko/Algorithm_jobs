#include <iostream>
#include <string.h>
using namespace std;
#define LEN 1000

int main() {
	char sen[LEN + 1];
	fgets(sen, sizeof(sen), stdin);
	int n = strlen(sen) - 1;

	if (n == 1) { cout << "YES"; }

	else if (n % 2 == 1) {
		int s = 0;
		while (sen[s] == sen[n - 1 - s]) {
			s += 1;
			if (s == n / 2) { cout << "YES"; break; }
		}
		if (s != n / 2) { cout << "NO"; }
	}

	else {
		int s = 0;
		while (sen[s] == sen[n - 1 - s]) {
			s += 1;
			if (s == n / 2 + 1) { cout << "YES"; break; }
		}
		if (s != n / 2 + 1) { cout << "NO"; }
	}
}