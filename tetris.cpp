#include <iostream>
#define CROSS 1000
#define DOWN 20
using namespace std;

void map_recovery(int map[CROSS + 2][DOWN + 2], int map_backup[CROSS + 2][DOWN + 2], int cross, int down);
int do_tetris(int map[CROSS + 2][DOWN + 2], int map_backup[CROSS + 2][DOWN + 2], int cross, int down, int index);

int main() {

	//조건
	int cross, down; // cross 가로 행 담당, down 세로 열 담당
	cin >> down >> cross; // 렬 행 순서로 입력되는 사이트의 불편한 진실
	int map[CROSS + 2][DOWN + 2] = { 0, };

	//입력
	for (int s = 1; s <= cross; s++) {
		for (int t = 1; t <= down; t++) {
			cin >> map[s][t];
		}
	}

	/*
	//확인
	for (int s = 1; s <= cross; s++) {
		for (int t = 1; t <= down; t++) {
			cout << map[s][t] << " ";
		}
		cout << endl;
	}
	*/

	// 탐색
	int index_depth[DOWN + 1] = { 0, };

	for (int t = 1; t <= down; t++) {
		for (int s = 1; s <= cross; s++) {
			if (map[s][t] == 1) {
				index_depth[t] = s; // 각 렬의 최상단 행의 인덱스 저장.
				break;
			}
			else { index_depth[t] = cross + 1; }
		}
	}

	// 백업용 맵 설정
	int map_backup[CROSS + 2][DOWN + 2] = { 0 , };
	for (int s = 1; s <= cross; s++) {
		for (int t = 1; t <= down; t++) {
			map_backup[s][t] = map[s][t];
		}
	}

	// 깊이 값에 따른 행렬별 일자 삽입 탐색
	int result[DOWN + 1] = { 0, };

	for (int s = 1; s <= down; s++) {
		int boom = 0;
		for (int t = index_depth[s] - 1; t >= 1; t--) {
			if (index_depth[s] <= 4) { result[s] = 0; break; }
			if (boom == 4) { break; }
			map[t][s] = 1;
			boom++;
		}
		result[s] = do_tetris(map, map_backup, cross, down, index_depth[s]-1);
	}

	// 깊이값에 따른 게임결과 최고값 탐색
	int value = 0;
	int index = 0;
//	cout << "최고값 출력:";
	for (int s = 1; s <= down; s++) {
//		cout << result[s] << " ";
		if (result[s] > value) {
			value = result[s];
			index = s;
		}
	}

	if (value != 0) {
		cout << index << " " << value;
	}
	else cout << 0 << " " << 0;
}

void map_recovery(int map[CROSS + 2][DOWN + 2], int map_backup[CROSS + 2][DOWN + 2], int cross, int down) {
	for (int s = 1; s <= cross; s++) {
		for (int t = 1; t <= down; t++) {
			map[s][t] = map_backup[s][t];
		}
	}
}

int do_tetris(int map[CROSS + 2][DOWN + 2], int map_backup[CROSS + 2][DOWN + 2], int cross, int down, int index) {
	int result = 0;
	
	for (int s = index; s >= 1; s--) {
		int counter = 0;
		for (int t=1; t<=down;t++){
			if (map[s][t] == 1) { counter+=1; }
			if (counter == down) { result++; }
		}
	}
	map_recovery(map, map_backup, cross, down);
	return result;
}
