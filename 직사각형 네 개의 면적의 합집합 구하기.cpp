#include <iostream>
#define CROSS 100
#define DOWN 100
#define CIRCLE 4
using namespace std;

class table {
public:
	int enable = 0;
};

class point {
public:
	int x_idx = 0;
	int y_idx = 0;
	int x_idx_2 = 0;
	int y_idx_2 = 0;
};

void map_point_marker(table map[CROSS + 2][DOWN + 2], point *pointer);
int surface(table map[CROSS + 2][DOWN + 2]);

int main() {

	// 맵 설정
	table map[CROSS + 2][CROSS + 2];

	// 사각형 설정
	point first,second,third,fourth;

	// 사각형 좌표값 입력
	cin >> first.x_idx >> first.y_idx >> first.x_idx_2 >> first.y_idx_2;
	cin >> second.x_idx >> second.y_idx >> second.x_idx_2 >> second.y_idx_2;
	cin >> third.x_idx >> third.y_idx >> third.x_idx_2 >> third.y_idx_2;
	cin >> fourth.x_idx >> fourth.y_idx >> fourth.x_idx_2 >> fourth.y_idx_2;

	// 사각형 좌표값 기반 지도 좌표 enable 설정
	map_point_marker(map, &first);
	map_point_marker(map, &second);
	map_point_marker(map, &third);
	map_point_marker(map, &fourth);

	int conclusion = 0;
	conclusion = surface(map);
	cout << conclusion;
}


void map_point_marker(table map[CROSS + 2][DOWN + 2], point *pointer) {

	for (int s = pointer->x_idx; s <= pointer->x_idx_2; s++) {
		for (int t = pointer->y_idx; t <= pointer->y_idx_2; t++) {
			map[s][t].enable = 1;
		}
	}
}

int surface(table map[CROSS + 2][DOWN + 2]) {

	int result = 0;
	for (int s = 1; s <= CROSS; s++) {
		for (int t = 1; t <= DOWN; t++) {
			if (map[t][s].enable == 1 && map[t + 1][s].enable == 1 && map[t][s + 1].enable == 1 && map[t + 1][s + 1].enable == 1) {
				result++;
			}
		}
	}
	return result;
}

