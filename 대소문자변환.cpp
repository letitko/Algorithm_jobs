#include <iostream>
#include <string.h>
using namespace std;
#define LEN 1000

int main() {

	char senten[LEN + 1];
	fgets(senten, sizeof(senten), stdin);
	int s = 0;
	while (!(senten[s] == NULL)) { // space(공백) != NULL('\0')이다.
		if (senten[s] <= 90 && senten[s] >= 65) { cout << (char)(senten[s] + 32); }
		else if (senten[s] >= 97 && senten[s] <= 122) { cout << (char)(senten[s] - 32); }
		else { cout << senten[s]; }
		s++;
	}

}