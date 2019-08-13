#include <iostream>
using namespace std;
#define MAP_SIZE 100

int mine_detect(int map[MAP_SIZE + 2][MAP_SIZE + 2], int cursor_x, int cursor_y) {
	
	int counter = 0;

	if (map[cursor_x - 1][cursor_y - 1] == 1) {
		counter++;
	}
	if (map[cursor_x - 1][cursor_y] == 1) {
		counter++;
	}
	if (map[cursor_x - 1][cursor_y + 1] == 1) {
		counter++;
	}
	if (map[cursor_x][cursor_y - 1] == 1) {
		counter++;
	}
	if (map[cursor_x][cursor_y + 1] == 1) {
		counter++;
	}
	if (map[cursor_x + 1][cursor_y - 1] == 1) {
		counter++;
	}
	if (map[cursor_x + 1][cursor_y] == 1) {
		counter++;
	}
	if (map[cursor_x + 1][cursor_y + 1] == 1) {
		counter++;
	}

	return counter;
}

int main() {

	int map[MAP_SIZE + 2][MAP_SIZE + 2] = { 0, };
	
	int x, y;
	cin >> x >> y;
	int cursor_x, cursor_y;
	cin >> cursor_x >> cursor_y;

	for (int s = 1; s <= x; s++) {
		for (int t = 1; t <= y; t++) {
			cin >> map[s][t];
		}
	}

	if (map[cursor_x][cursor_y] == 1) {
		cout << "game over" << endl;
		return 0;
	}

	int result = 0;
	result = mine_detect(map, cursor_x, cursor_y);
	cout << result << endl;

	return 0;
}