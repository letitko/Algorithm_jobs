#include <iostream>
#define TILE 100
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int middle_point = M / 2;
	if (M % 2 == 1) { middle_point += 1; }

	static int cube[TILE+1][TILE+1];
	static int cube_backup[TILE + 1][TILE + 1];

	for (int s = 1; s <= N; s++) {
		for (int i = 1; i <= M; i++) {
			cin >> cube[s][i];
			cube_backup[s][M-i+1] = cube[s][i];
		}
	}

	for (int s = 1; s <= N; s++) {
		for (int i = 1; i <= M; i++) {
			cout << cube_backup[s][i] << " ";
		}
		cout << endl;
	}
}