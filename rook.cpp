#include <iostream>
#define CHESSBOARD 8
#define TRUE 1;
#define FASLE 0;
using namespace std;

typedef class King {
public:
	int data = 1;
	int cross_index;
	int down_index;
}king;

bool is_king_danger(int map[CHESSBOARD + 2][CHESSBOARD + 2], int x, int y);

int main() {
	king arthur;
	int map[CHESSBOARD + 2][CHESSBOARD + 2] = { 0, };

	// insert boundary
	for (int s = 0; s <= CHESSBOARD + 1; s++) {
		map[0][s] = 3;
	}
	for (int s = 0; s <= CHESSBOARD + 1; s++) {
		map[CHESSBOARD + 1][s] = 3;
	}
	for (int s = 0; s <= CHESSBOARD + 1; s++) {
		map[s][0] = 3;
	}
	for (int s = 0; s <= CHESSBOARD + 1; s++) {
		map[s][CHESSBOARD + 1] = 3;
	}


	// insert data
	for (int s = 1; s <= CHESSBOARD; s++) {
		for (int t = 1; t <= CHESSBOARD; t++) {
			cin >> map[s][t];
		}
	}

	// find king
	for (int s = 1; s <= CHESSBOARD; s++) {
		for (int t = 1; t <= CHESSBOARD; t++) {
			if (map[s][t] == 1) {
				//				cout << "¿ÕÀ» Ã£¾Ò´Ù : " << endl;
				arthur.cross_index = s;
				arthur.down_index = t;
				//				cout << arthur.cross_index << " " << arthur.down_index << endl;
				arthur.data = 1;
			}
		}
	}

	// is king danger ?
	if (is_king_danger(map, arthur.cross_index, arthur.down_index)) {
		cout << 1;
	}
	else { cout << 0; }

	return 0;
}

bool is_king_danger(int map[CHESSBOARD + 2][CHESSBOARD + 2], int x, int y) {
	//	cout << "*************" << map[2][7] << "***********" << endl;

	for (int s = y; s >= 0; s--) {
		if (map[x][s] == 3) {
			break;
		}

		else if (map[x][s] == 2) {
			return 1;
		}
	}

	for (int s = y; s <= CHESSBOARD + 1; s++) {
		if (map[x][s] == 3) {
			break;
		}

		else if (map[x][s] == 2) {
			return 1;
		}
	}

	for (int s = x; s >= 0; s--) {
		if (map[s][y] == 3) {
			break;
		}

		else if (map[s][y] == 2) {
			return 1;
		}
	}

	for (int s = x; s <= CHESSBOARD + 1; s++) {
		if (map[s][y] == 3) {
			break;
		}

		else if (map[s][y] == 2) {
			return 1;
		}
	}

	return 0;
}

