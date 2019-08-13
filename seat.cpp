#include <iostream>
using namespace std;

typedef class SEAT {
public:
	int data = 0;
	int number = 0;
}seats;

int main() {

	// 데이터 생성
	static seats seat[1000 + 2][1000 + 2];
	int x, y; // x가로(열) y세로(행)
	int total_customer;
	cin >> x >> y;
	cin >> total_customer;

	// 행렬 바운드리 데이터 생성
	for (int s = 0; s <= y + 1; s++) {
		seat[s][0].data = 2;
	}
	for (int s = 0; s <= y + 1; s++) {
		seat[s][x + 1].data = 2;
	}
	for (int s = 0; s <= x + 1; s++) {
		seat[0][s].data = 2;
	}
	for (int s = 0; s <= x + 1; s++) {
		seat[y + 1][s].data = 2;
	}
	/*
	for (int s = 0; s <= y + 1; s++) {
		for (int t = 0; t <= x + 1; t++) {
			cout << seat[s][t].data << " ";
		}
		cout << endl;
	}
	*/
	// 애초에 좌석수보다 클라이언트 대기자 번호가 높다면
	if (total_customer > x*y) {
		cout << 0;
		return 0;
	}

	// 잔여좌석이 애초에 0개이라면
	if (total_customer == 1 && (x == 0 || y == 0)) {
		cout << 0;
		return 0;
	}

	// 고객이 한명이고 좌석이 있다면
	else if (total_customer == 1 && (x >= 1 && y >= 1)) {
		cout << 1 << " " << 1;
		return 0;
	}

	// 고객이 한명 이상이고 좌석이 있다면, 좌석 채우기 시작
	// 반시계 회전 [y축][x축]
	int index_x = 1, index_y = 1;
	seat[index_y][index_x].data = 1;
	seat[index_y][index_x].number = 1;

	int current = 1;

	while (current != total_customer) {

		if (seat[index_y - 1][index_x].data != 0 && seat[index_y][index_x - 1].data != 0 && seat[index_y + 1][index_x].data == 0) {
			seat[index_y + 1][index_x].data = 1;
			seat[index_y + 1][index_x].number = seat[index_y][index_x].number + 1;
			index_y++; current++;
		}

		else if (seat[index_y + 1][index_x].data != 0 && seat[index_y][index_x - 1].data != 0 && seat[index_y][index_x + 1].data == 0) {
			seat[index_y][index_x + 1].data = 1;
			seat[index_y][index_x + 1].number = seat[index_y][index_x].number + 1;
			index_x++; current++;
		}

		else if (seat[index_y + 1][index_x].data != 0 && seat[index_y][index_x + 1].data != 0 && seat[index_y - 1][index_x].data == 0) {
			seat[index_y - 1][index_x].data = 1;
			seat[index_y - 1][index_x].number = seat[index_y][index_x].number + 1;
			index_y--; current++;
		}

		else if (seat[index_y - 1][index_x].data != 0 && seat[index_y][index_x + 1].data != 0 && seat[index_y][index_x - 1].data == 0) {
			seat[index_y][index_x - 1].data = 1;
			seat[index_y][index_x - 1].number = seat[index_y][index_x].number + 1;
			index_x--; current++;
		}

	}
	

	//탐색이 제일 중요했음
	for (int s = 1; s <= x; s++) {
		for (int t = 1; t <= y; t++) {
			if (total_customer == seat[t][s].number) {
				cout << s << " " << t << endl;
			}
		}
	}

	/*
	for (int s = 0; s <= y + 1; s++) {
		for (int t = 0; t <= x + 1; t++) {
			cout << seat[s][t].number << " ";
		}
		cout << endl;
	}
	*/
		return 0;
}