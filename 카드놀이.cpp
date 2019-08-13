#include <iostream>
using namespace std;
#define MAX 100008

// ī�带 �̴� ����� ���� ����غ���
// idx : n-3 n-2 n-1 n �����Ͽ�
// T[N]: �� �̴� ���� ������ ���� ����� ���� �ִ�.
// case=1: T(N) = T(N-1) -> ���� ���� �ʰ� �Ǵ� ��� �� ���������� �ְ� ���ռ��� �� �ڽ� ���� �ȴ�.
// case=2; T(N) = T(N-2)+N -> ���� �̰� �Ǵ� ��� �� ���� ���������� ���ڸ� �̴� ����� ���� �ִ�.
// case=3; T(N) = T(N-3)+N-1+N -> ���� �̰� ���� ������ �̰� �Ǵ� ��� ���� �������� �̴� ����� ���� �������� ���ϸ� �ȴ�.

int T[MAX];
int card_data[MAX];
int total_cards;

int trap_card() {
	// case=1: T(N) = T(N-1)
	// case=2; T(N) = T(N-2)+N
	// case=3; T(N) = T(N-3)+N-1+N

	int case_1;
	int case_2;
	int case_3;

	T[0] = card_data[0];
	T[1] = card_data[0] + card_data[1];

	int the_biggest = 0;
	if (card_data[0] + card_data[1] >= the_biggest) {
		the_biggest = card_data[0] + card_data[1];
	}
	if (card_data[1] + card_data[2] >= the_biggest) {
		the_biggest = card_data[1] + card_data[2];
	}
	if (card_data[0] + card_data[2] >= the_biggest) {
		the_biggest = card_data[0] + card_data[2];
	}

	T[2] = the_biggest;

	for (int idx = 3; idx < total_cards; idx++) {
		case_1 = T[idx - 3] + card_data[idx - 1] + card_data[idx];
		case_2 = T[idx - 2] + card_data[idx];
		case_3 = T[idx - 1];

		int case_biggest = 0;
		if (case_1 >= case_biggest) {
			case_biggest = case_1;
		}
		if (case_2 >= case_biggest) {
			case_biggest = case_2;
		}
		if (case_3 >= case_biggest) {
			case_biggest = case_3;
		}

		T[idx] = case_biggest;
		//	cout << "idx:" << idx << " value:"<< T[idx] << endl;
	}



	return T[total_cards - 1];
}

int main() {

	cin >> total_cards;

	for (int s = 0; s < total_cards; s++) {
		cin >> card_data[s];
	}

	if (total_cards <= 3) {
		if (total_cards == 1) {
			cout << card_data[0];
		}
		else if (total_cards == 2) {
			cout << card_data[0] + card_data[1];
		}
		else {
			int the_biggest = 0;
			if (card_data[0] + card_data[1] >= the_biggest) {
				the_biggest = card_data[0] + card_data[1];
			}
			if (card_data[1] + card_data[2] >= the_biggest) {
				the_biggest = card_data[1] + card_data[2];
			}
			if (card_data[0] + card_data[2] >= the_biggest) {
				the_biggest = card_data[0] + card_data[2];
			}
			cout << the_biggest << endl;
		}
	}
	else {
		cout << trap_card() << endl;
	}
}