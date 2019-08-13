#include <iostream>
using namespace std;

typedef class SEAT {
public:
	int data = 0;
	int number = 0;
}seats;

int main() {

	// ������ ����
	static seats seat[1000 + 2][1000 + 2];
	int x, y; // x����(��) y����(��)
	int total_customer;
	cin >> x >> y;
	cin >> total_customer;

	// ��� �ٿ�帮 ������ ����
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
	// ���ʿ� �¼������� Ŭ���̾�Ʈ ����� ��ȣ�� ���ٸ�
	if (total_customer > x*y) {
		cout << 0;
		return 0;
	}

	// �ܿ��¼��� ���ʿ� 0���̶��
	if (total_customer == 1 && (x == 0 || y == 0)) {
		cout << 0;
		return 0;
	}

	// ���� �Ѹ��̰� �¼��� �ִٸ�
	else if (total_customer == 1 && (x >= 1 && y >= 1)) {
		cout << 1 << " " << 1;
		return 0;
	}

	// ���� �Ѹ� �̻��̰� �¼��� �ִٸ�, �¼� ä��� ����
	// �ݽð� ȸ�� [y��][x��]
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
	

	//Ž���� ���� �߿�����
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