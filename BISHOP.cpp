#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n;
int map[10 + 2][10 + 2];

void left_top(int s, int t) {

	if (map[s][t] == 1) {
		map[s][t] = 0;
	}

	if (s - 1 >= 1 && t - 1 >= 1) {
		left_top(s - 1, t - 1);
	}

	return;
}

void right_top(int s, int t) {

	if (map[s][t] == 1) {
		map[s][t] = 0;
	}

	if (s - 1 >= 1 && t + 1 <= n) {
		right_top(s - 1, t + 1);
	}

	return;
}

void left_down(int s, int t) {

	if (map[s][t] == 1) {
		map[s][t] = 0;
	}

	if (s + 1 <= n && t - 1 >= 1) {
		left_down(s + 1, t - 1);
	}
	return;
}

void right_down(int s, int t) {

	if (map[s][t] == 1) {
		map[s][t] = 0;
	}

	if (s + 1 <= n && t + 1 <= n) {
		right_down(s + 1, t + 1);
	}
	return;
}


void DFS(int s, int t) {

	left_down(s + 1, t - 1);
	left_top(s - 1, t - 1);
	right_top(s - 1, t + 1);
	right_down(s + 1, t + 1);

	return;
}

int counter = 0;

int main() {
	cin >> n;

	for (int s = 1; s <= n; s++) {
		for (int t = 1; t <= n; t++) {
			cin >> map[s][t];
		}
	}

	for (int s = 1; s <= n; s++) {
		for (int t = 1; t <= n; t++) {
			if (map[s][t] == 1) {
				DFS(s, t);
				counter += 1;
			}
		}
	}

	for (int s = 1; s <= n; s++) {
		for (int t = 1; t <= n; t++) {
			cout << map[s][t] << ' ';
		} cout << endl;
	}

	cout << counter << endl;
}