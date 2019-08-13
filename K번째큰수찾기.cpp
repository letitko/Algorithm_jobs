#include <iostream>
using namespace std;
#define LEN 100000

int main() {
	// 버블 선택도
	static int num[LEN+1];

	int N, K;
	cin >> N >> K;
	int last = N;

	for (int s = 1; s <= N; s ++ ) {
		cin >> num[s];
	}

	int counter = 0;
	for (int s = N; s >= 1; s--) {
		for (int t = 2; t <= s; t++) {
			if (num[t - 1] > num[t]) {
				int s = num[t];
				num[t] = num[t-1];
				num[t - 1] = s;
			}
		}
		counter += 1;
		if (counter == K) { break; }
	}

	cout << num[N - K + 1] << endl;
}