#include <iostream>
#define MAXOFARR 9
using namespace std;

int main() {
	int maxofarr[MAXOFARR+1][MAXOFARR+1];
	
	for (int s = 1; s <= MAXOFARR; s++) {
		for (int t = 1; t <= MAXOFARR; t++) {
			cin >> maxofarr[s][t];
		}
	}

	int who_is_max=0;
	int cross_memorizer = 0;
	int down_memorizer = 0;

	for (int s = 1; s <= MAXOFARR; s++) {
		for (int t = 1; t <= MAXOFARR; t++) {
			if (who_is_max <= maxofarr[s][t]) {
				who_is_max = maxofarr[s][t];
				cross_memorizer = s;
				down_memorizer = t;
			}
		}
	}

	for (int s = 1; s <= MAXOFARR; s++) {
		for (int t = 1; t <= MAXOFARR; t++) {
			if (who_is_max == maxofarr[s][t] &&
				cross_memorizer >= s) {
				cross_memorizer = s;
				down_memorizer = t;
				s = MAXOFARR + 1;
				break;
			}
		}
	}

	cout << who_is_max << endl;
	cout << cross_memorizer << " " << down_memorizer;
}