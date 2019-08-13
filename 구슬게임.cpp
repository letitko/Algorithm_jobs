#include <iostream>
#include <string.h>
using namespace std;

bool beads[1000001];
int dest_bead = 0;

int main() {

	// 1 2 3 4 5 6 7 8 9 10 11 ...
	// o o o x o o o x o  o  o ...
	// ��, 4�� ����� ��쿡�� ���̱��.

	cin >> dest_bead;
	memset(beads, 1, sizeof(beads));
	beads[4] = 0;
	for (int s = 1; s <= dest_bead - 4; s++) {
		beads[s + 4] = beads[s];
	}
	if (beads[dest_bead] == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}