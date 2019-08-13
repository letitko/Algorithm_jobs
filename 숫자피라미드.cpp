#include <iostream>
#define LENGTH 10
using namespace std;

int nums[LENGTH] = { 0,1,2,3,4,5,6,7,8,9 };

void void_printer(int current, int total_floor) {
	for (int t = 0; t < total_floor - current; t++) {
		cout << " ";
	}
}

int main() {
	int total_floor = 0;
	int current_floor = 1;
	int start_num = 0;
	int forward_bias = 0;
	int backward_bias = 0;

	cin >> total_floor;
	cin >> start_num;
	backward_bias = start_num;

	while (current_floor != total_floor + 1) {
		switch (current_floor%2)
		{
		
		// Â¦¼öÃþÀÇ °æ¿ì -> ¼ø¹æÇâ
		case 0:
			void_printer(current_floor, total_floor);
			forward_bias += 1 ;
			if (forward_bias == 10) {
				forward_bias = 1;
			}
			for (int s = 1; s <= 2 * (current_floor - 1) + 1; s++) {
				cout << nums[forward_bias];
				forward_bias += 1;
				if (forward_bias == 10) {
					forward_bias = 1;
				}
				backward_bias = forward_bias;
				if (backward_bias == 10) {
					backward_bias = 1;
				}
			}
			//cout << "          "<< "Â¦¼öÃþ :" << current_floor << endl;
			cout << endl;
			current_floor++;
			break;

		// È¦¼öÃþÀÇ °æ¿ì -> ¿ª¹æÇâ
		case 1:
			void_printer(current_floor, total_floor);
			for (int s = 1; s <= 2 * (current_floor - 1); s++) {
				backward_bias += 1;
				if (backward_bias == 10) {
					backward_bias = 1;
				}
			}
			forward_bias = backward_bias;
			for (int p = 1; p <= 2 * (current_floor - 1)+1; p++) {
				cout << nums[backward_bias];
				backward_bias -= 1;
				if (backward_bias == 0) {
					backward_bias = 9;
				}
			}
			//cout << "          " << "È¦¼öÃþ :" << current_floor << endl;
			cout << endl;
			current_floor++;
			break;

		default:
			cout << "error" << endl;
		}
	}

	return 0;
}