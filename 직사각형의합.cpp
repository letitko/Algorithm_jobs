#include <iostream>
#define LEN 1000000
using namespace std;

int square[1000][1000] = { 0, };
int sum_square[1000][1000] = { 0, };

int main() {

	int n, m;
	int total_quest;
	cin >> n >> m;
	cin >> total_quest;

	for (int s = 0; s < n; s++) {
		for (int t = 0; t < m; t++) {
			cin >> square[s][t];
			if (t == 0) {
				sum_square[s][t] = square[s][t];
			}
			else {
				sum_square[s][t] += (square[s][t] + sum_square[s][t - 1]);
			}
		}
	}

	int idx_a;
	int idx_b;
	int idx_c;
	int idx_d;

	for (int i = 0; i < total_quest; i++) {
		cin >> idx_a;
		cin >> idx_b;
		cin >> idx_c;
		cin >> idx_d;
		// a->c, b->d
		// a->c 가로로 늘어남
		// b->d 세로로 늘어남
		int sum = 0;
		for (int k = idx_a; k <= idx_c; k++) {
			if (idx_b == 0) { sum += sum_square[k][idx_d]; }
			else {
				sum += (sum_square[k][idx_d] - sum_square[k][idx_b - 1]);
			}
		}
		cout << sum << endl;
	}

}