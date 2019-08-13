#include <iostream>
#include <string.h>
using namespace std;
#define TIM 100
#define LEN 100

class arry {
public:
	char str[LEN + 1];
	int priority = 0;
};

int main() {

	int total = 0;
	char enter = 0;
	cin >> total;
	cin.get(enter);
	arry arrays[TIM + 1];

	for (int s = 1; s <= total; s++) {
		fgets(arrays[s].str, sizeof(arrays[s].str), stdin);
	}
	// ������ fgets�� �¶��� �����Ϸ����� ������ ù���� ���ΰ��� LF�� �� �޾Ƽ� NULL�ڸ��� �����ϰ� NULL�� ��ĭ�ڷ� ����
	int detecter = 0;
	while (!(arrays[total].str[detecter] == NULL)) {
		detecter++;
	}
	arrays[total].str[detecter] = 10;
	arrays[total].str[detecter + 1] = NULL;

	for (int s = 1; s <= total; s++) {
		for (int t = 1; t <= total; t++) {
			if (t == s) { continue; }
			if (0 > strcmp(arrays[s].str, arrays[t].str)) {
				arrays[t].priority++;
			}
		}
	}


	//�켱���� �׽�Ʈ
	/*
	for (int t = 1; t <= total; t++) {
	cout << arrays[t].priority;
	cout << endl;
	}
	*/

	int rank[LEN + 1];
	rank[0] = 5882;
	for (int s = 1; s <= total; s++) {
		rank[s] = arrays[s].priority;
	}

	// ��������
	for (int s = 2; s <= total; s++) {
		int swap = 0;
		for (int t = s; t >= 2; t--) {
			if (rank[t] < rank[t - 1]) {
				swap = rank[t - 1];
				rank[t - 1] = rank[t];
				rank[t] = swap;
			}
			else { break; }
		}
	}

	// ����üũ
	//	for (int s = 1; s <= total; s++) {
	//		cout << rank[s] << endl;
	//	}
	//

	int memorizer = 15885588;
	for (int s = 1; s <= total; s++) {
		if (memorizer == rank[s]) { continue; }

		for (int t = 1; t <= total; t++) {
			if (rank[s] == arrays[t].priority) {
				int q = 0;
				while (!(arrays[t].str[q] == NULL)) {
					cout << (char)(arrays[t].str[q]);
					q++;
				}
			}
		}
		memorizer = rank[s];
	}
}