#include <iostream>
using namespace std;
#define MAX 100008

// 카드를 뽑는 경우의 수를 고려해본다
// idx : n-3 n-2 n-1 n 에대하여
// T[N]: 을 뽑는 경우는 다음과 같은 경우의 수가 있다.
// case=1: T(N) = T(N-1) -> 나를 뽑지 않게 되는 경우 나 직전까지의 최고 조합수가 내 자신 값이 된다.
// case=2; T(N) = T(N-2)+N -> 나를 뽑게 되는 경우 중 나의 전전까지의 숫자를 뽑는 경우의 수가 있다.
// case=3; T(N) = T(N-3)+N-1+N -> 나를 뽑고 나의 직전을 뽑게 되는 경우 나의 전전전을 뽑는 경우의 수중 최적값을 더하면 된다.

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