#include <iostream>
using namespace std;

int n;
int button[100000][3];
int dp_button[100000][3];

int main() {
	cin >> n;
	for (int s = 0; s < n; s++) {
		for (int t = 0; t < 3; t++) {
			cin >> button[s][t];
		}
	}

	dp_button[0][0] = button[0][0];
	dp_button[0][1] = button[0][1];
	dp_button[0][2] = button[0][2];

	for (int s = 1; s < n; s++) {
		for (int t = 0; t < 3; t++) {
			if (t == 0) {
				dp_button[s][t] = (button[s][t] + (dp_button[s - 1][1] > dp_button[s - 1][2] ? dp_button[s - 1][1] : dp_button[s - 1][2]));
			}
			else if (t == 1) {
				dp_button[s][t] = (button[s][t] + (dp_button[s - 1][0] > dp_button[s - 1][2] ? dp_button[s - 1][0] : dp_button[s - 1][2]));
			}
			else {
				dp_button[s][t] = (button[s][t] + (dp_button[s - 1][0] > dp_button[s - 1][1] ? dp_button[s - 1][0] : dp_button[s - 1][1]));
			}
		}
	}

	int biggest = 0;
	biggest = dp_button[n - 1][0];
	if (biggest < dp_button[n - 1][1]) {
		biggest = dp_button[n - 1][1];
	}
	if (biggest < dp_button[n - 1][2]) {
		biggest = dp_button[n - 1][2];
	}

	cout << biggest;
}