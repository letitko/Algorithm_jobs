#include <iostream>
#include <string.h>
using namespace std;
#define LEN 1000

int main() {

	char senten[LEN + 1];
	char senten2[LEN + 1];

	fgets(senten, sizeof(senten), stdin);
	int cnt = 0;
	int s = 0;

	while (!(senten[cnt] == NULL)) {
		cnt++;
	}
	
	int last = cnt;
	while (cnt>=0) {
		senten2[s] = senten[cnt-1];
		s++;
		cnt--;
	}
	senten2[s] = senten[last];
	
	s = 0;
	while(!(senten2[s]==NULL)){
		cout << senten2[s];
		s++;
	}
}