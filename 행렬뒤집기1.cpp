#include <iostream>
#define TILE 10
using namespace std;

int main() {

	int nums[TILE + 1][TILE + 1] = { 0, };

	int N; cin >> N;

	for (int num = 1; num <= N; num++) {
		for (int k = 1; k <= TILE; k++) {
			if (nums[k][num] == 0) {
				nums[k][num] = 1;
			}
			else if (nums[k][num] == 1) {
				nums[k][num] = 0;
			}
		}


		for (int s = 1; s <= TILE; s++) {
			if (nums[num][s] == 0) {
				nums[num][s] = 1;
			}
			else if (nums[num][s] == 1) {
				nums[num][s] = 0;
			}
		}
	}

	for (int s = 1; s <= N; s++) {
			nums[s][s] = 1;
		}

	for (int s = 1; s <= TILE; s++) {
		for (int t = 1; t <= TILE; t++) {
			cout << nums[s][t] << " ";
		}
		cout << endl;
	}
}