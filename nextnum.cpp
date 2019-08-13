#include <iostream>
using namespace std;

int main() {
	while(1){
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;
		int detecter;
		if (a1 == 0 && a2 == 0 && a3 == 0) { break; }
	else if (a2-a1 == a3 - a2) {
		cout << "AP ";
		detecter = a2 - a1;
		cout << a3 + detecter << endl;
	}
	else { detecter = a2 / a1; 
	cout << "GP ";
	cout << a3*detecter << endl;
	}
	}
}