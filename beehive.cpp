#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;
	int M = N;
	int floor = 1;
	N = 1;

	while (M - 6 * N >0) {
		M -= 6 * N;
		floor +=1 ;
		N += 1 ;
		if (M - 6 * N != 0 && M - 6 * N < 0) {
			floor++;
			break;
		}
	}
	cout << floor;
}