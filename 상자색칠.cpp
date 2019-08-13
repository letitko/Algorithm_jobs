#include <iostream>
#define TOTAL 1000
using namespace std;

class number {
public:
	int data;
	int count = 0;
};

int main() {

	//set std_data
	number standard_number[TOTAL + 1];
	for (int s = 1; s <= TOTAL; s++) {
		standard_number[s].data = s;
	}

	int max_num;
	cin >> max_num;
	
	//get data
	int nums[TOTAL + 1];
	for (int s = 1; s <= max_num; s++) {
		cin >> nums[s];
	}

	//count the kinds of number;
	for (int s = 1; s <= max_num; s++) {
		for (int t = 1; t <= max_num; t++) {
			if (nums[s] == standard_number[t].data) {
				standard_number[t].count++;
			}
		}
	}

	//can we paint the dimension?
	int how_many = 0;
	int are_they_over_two = 0;

	//step 1. how many colors do I have
	for (int s = 1; s <= max_num; s++) {
		if (standard_number[s].count != 0) {
			how_many++;
		}
	}

	//step 2. how many over_two do I have
	for (int s = 1; s <= max_num; s++) {
		if (standard_number[s].count >= 2) {
			are_they_over_two++;
		}
	}


	switch (how_many)
	{
	case 0:
		cout << "NO";
			break;
	case 1:
		cout << "NO";
			break;
	case 2:
		cout << "NO";
			break;
	case 3:
		if (are_they_over_two >= 3) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
			break;
	case 4:
		if (are_they_over_two >= 2) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		break;
	case 5:
		if (are_they_over_two >= 1) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		break;


	default:
		cout << "YES";
		break;
	}

	return 0;
}