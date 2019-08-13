#include <iostream>
using namespace std;
#define MAP_SIZE 100

class unit {

	public:
		int x;
		int y;
		int range;
};

void range_mask(int map[MAP_SIZE + 2][MAP_SIZE + 2], int x, int y, int range) {
	
	for (int counter = 1; counter <= range; counter++) {
		if (y + counter <= 100) { map[x][y + counter] = counter; }
		if (y - counter >= 1) { map[x][y - counter] = counter; }
		if (x + counter <= 100) { map[x + counter][y] = counter; }
		if (x - counter >= 1) { map[x - counter][y] = counter; }
	}
}

void mask_upgrader(int map[MAP_SIZE + 2][MAP_SIZE + 2], int map_size,int x, int y, int range) {

	for (int s = 1; s <= map_size; s ++ ) {
		for (int t = 1; t <= map_size; t++) {
			if (s!=x && map[s][t] != 0) {
				for (int counter=1; counter <= range; counter++) {
					if (t + counter <= 100 && (map[s][t] + counter) <=range ) { map[s][t + counter] = map[s][t]+counter; }
					if (t - counter >= 1 && (map[s][t] + counter) <= range) { map[s][t - counter] = map[s][t]+counter; }
				}
				break;
			}
		}
	}
}

int main() {

	int	map[MAP_SIZE + 2][MAP_SIZE + 2]={ 0, };
	int map_size;
	unit gay;
	cin >> map_size;
	cin >> gay.x >> gay.y;
	cin >> gay.range;

	range_mask(map, gay.x, gay.y, gay.range);
	mask_upgrader(map, map_size, gay.x, gay.y, gay.range);

	// »Æ¿Œ
	for (int t = 1; t <= map_size; t++) {
		for (int s = 1; s <= map_size; s++) {
			if (s == gay.y && t == gay.x) { cout << "x "; }
			else { cout << map[t][s] << " "; }
		}
		cout << endl;
	}

}