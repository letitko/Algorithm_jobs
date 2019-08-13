#include <iostream>
#include <string.h>
#define LEN 1000
using namespace std;

int main() {

	char sen[LEN + 1];
	fgets(sen, sizeof(sen), stdin);

	int op = 0;
	char alpha = sen[0];
	int counter = 0;


	while (!(sen[op] == NULL)) {

		if (sen[op] == alpha) {
			counter++;
			op++;
		}
		else if (sen[op] != alpha) {
			if (counter > 1) { cout << counter; }
			cout << alpha;
			counter = 0;
			alpha = sen[op];
			counter++;
			op++;
		}
	}
	if (counter >1) { cout << counter; }
	cout << alpha;
	cout << endl;
}