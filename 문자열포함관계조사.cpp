#include <iostream>
#include <string.h>
using namespace std;
#define LEN 1000

int main() {

	char sent_1[LEN + 1];
	char sent_2[LEN + 1];
	fgets(sent_1, sizeof(sent_1), stdin);
	fgets(sent_2, sizeof(sent_2), stdin);

	int cnt = 0;
	while (sent_2[cnt] != NULL){ 
//		cout << cnt << " ";
		cnt++;
	}
	int last = cnt;

	if (strlen(sent_1) >= strlen(sent_2)) {
		int tof = 0;
		for(int t=0;t<LEN-last;t++){ // 이거 한문장이 중요하다
			if(sent_1[t]==sent_2[0]){
				int counter=0;
					for (int s = 0; s <= last; s++) {
						if (sent_1[t + s] == sent_2[s]) {
							counter+=1;
							if (counter == last) { cout << "YES"; tof = 1; break; }
						}
				}
			}
		}
	if(tof==0){
	cout << "NO";
	}
	}
	else { cout << "NO"; }
}