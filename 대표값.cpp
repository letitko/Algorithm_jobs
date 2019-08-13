#include <iostream>
#define LEN 10
using namespace std;

typedef class NUM {
	public:
		int data = 0;
		int count = 0;
}numeric ;

int main() {
	int nums[LEN+1];

	numeric mask[100 + 1];

	for (int t = 1; t <= 100; t++) {
		mask[t].data = t*10;
	}

	for (int s = 1; s <= LEN; s++) {
		cin >> nums[s];
	}

	for (int s = 1; s <= LEN; s++) {
		for (int t=0; t<=100;t++){
			if (mask[t].data==nums[s]) {
				mask[t].count ++;
			}
		}
	}

	int finder=0;
	int biggest = 0;

	for (int t = 0; t <= 100; t++) {
		if (finder <= mask[t].count) {
			finder = mask[t].count;
			biggest = mask[t].data;
		}
	}

	for (int t = 0; t <= 100; t++) {
		if (finder == mask[t].count) {
			biggest = mask[t].data;
			break;
		}
	}

	int sum = 0;
	int total = 0;
	int avr = 0;

	for (int t = 0; t <= 100; t++) {
		sum += mask[t].count * mask[t].data;
		total += mask[t].count;
		}

	avr = sum / total;
	
	cout << avr << endl;
	cout << biggest << endl;
}
