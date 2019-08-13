#include <iostream>
#include <string.h>
using namespace std;
#define LEN 100000

int main() {

	char senten[LEN + 1];
	fgets(senten, sizeof(senten), stdin);
	int s = 0;
	while (!(senten[s] == NULL)) { // space(공백) != NULL('\0')이다.
		if (senten[s] == 32) { s++; }
		else { cout << (char)senten[s];	s++; }
	}
}