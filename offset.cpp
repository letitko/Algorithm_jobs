#include <iostream>
using namespace std;

typedef class INFO {
public:
	int nums = 0;
	int calculate = 0;
	char hi = '*';
}info;

int main() {
	
	static info array[7][7] = { 0, };

	//모서리 참조 구간

	for (int i = 0; i <= 6; i++) {
		array[i][6].nums = 10;
	}

	for (int i = 0; i <= 6; i++) {
		array[i][0].nums = 10;
	}

	for (int i = 0; i <= 6; i++) {
		array[0][i].nums = 10;
	}

	for (int i = 0; i <= 6; i++) {
		array[6][i].nums = 10;
	}

	//값 입력
	for (int s = 1; s <= 5; s++) {
		for (int i = 1; i <= 5; i++) {
			cin >> array[s][i].nums;
		}
	}

	//비교 러시 실행
	for (int s = 1; s <= 5; s++) {
		for (int i = 1; i <= 5; i++) {
			if (array[s][i].nums < array[s][i - 1].nums) {
				array[s][i].calculate++;
			}
			if (array[s][i].nums < array[s][i + 1].nums) {
				array[s][i].calculate++;
			}
			if (array[s][i].nums < array[s + 1][i].nums) {
				array[s][i].calculate++;
			}
			if (array[s][i].nums < array[s - 1][i].nums) {
				array[s][i].calculate++;
			}
		}
	}

	for (int s = 1; s <= 5; s++) {
		for (int i = 1; i <= 5; i++) {
			if (array[s][i].calculate == 4) {
				cout << array[s][i].hi;
			}
			else {
				cout << array[s][i].nums;
			}
			cout << " ";
		}
		cout << endl;
	}
}