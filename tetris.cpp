#include <iostream>
#define CROSS 1000
#define DOWN 20
using namespace std;

void map_recovery(int map[CROSS + 2][DOWN + 2], int map_backup[CROSS + 2][DOWN + 2], int cross, int down);
int do_tetris(int map[CROSS + 2][DOWN + 2], int map_backup[CROSS + 2][DOWN + 2], int cross, int down, int index);

int main() {

	//����
	int cross, down; // cross ���� �� ���, down ���� �� ���
	cin >> down >> cross; // �� �� ������ �ԷµǴ� ����Ʈ�� ������ ����
	int map[CROSS + 2][DOWN + 2] = { 0, };

	//�Է�
	for (int s = 1; s <= cross; s++) {
		for (int t = 1; t <= down; t++) {
			cin >> map[s][t];
		}
	}

	/*
	//Ȯ��
	for (int s = 1; s <= cross; s++) {
		for (int t = 1; t <= down; t++) {
			cout << map[s][t] << " ";
		}
		cout << endl;
	}
	*/

	// Ž��
	int index_depth[DOWN + 1] = { 0, };

	for (int t = 1; t <= down; t++) {
		for (int s = 1; s <= cross; s++) {
			if (map[s][t] == 1) {
				index_depth[t] = s; // �� ���� �ֻ�� ���� �ε��� ����.
				break;
			}
			else { index_depth[t] = cross + 1; }
		}
	}

	// ����� �� ����
	int map_backup[CROSS + 2][DOWN + 2] = { 0 , };
	for (int s = 1; s <= cross; s++) {
		for (int t = 1; t <= down; t++) {
			map_backup[s][t] = map[s][t];
		}
	}

	// ���� ���� ���� ��ĺ� ���� ���� Ž��
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

	// ���̰��� ���� ���Ӱ�� �ְ� Ž��
	int value = 0;
	int index = 0;
//	cout << "�ְ� ���:";
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
