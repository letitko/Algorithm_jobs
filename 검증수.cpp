#include <iostream>
#define LEN 6
using namespace std;

int quality_finder(int *ptr) {
	int sum = 0;
	for (int s = 1; s <= 5; s++) {
		++ptr;
		sum += (*ptr) *(*ptr);

	}
	return sum % 10;
	
}

int main() {

	int array[LEN] = { 0, };
	for (int s = 1; s <= LEN - 1; s++) {
		cin >> array[s];
	}

	cout << quality_finder(array);
	

}