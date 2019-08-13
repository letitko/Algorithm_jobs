#include <iostream>
using namespace std;
#define LEN 100

class nu {
public:
	int data = 0;
	int counter = 0;
};

int main() {
	int n;
	cin >> n;

	nu num[LEN + 1];
	for (int s = 1; s <= n; s++) {
		cin >> num[s].data;
	}

	for (int s = 1; s <= n; s++) {
	//	cout << "Å½»ö" << s << "´Ü°è" << endl;
		for (int t = 1; t <= num[s].data; t++) {
			if (num[s].data % t == 0) {
				num[s].counter += 1;
		//		cout << "process" << " " << num[s].counter << " ";
				if (num[s].counter > 2) {
					break;
				}
			}
		//	cout << endl;
		}
	}

	int how_many = 0;

	for (int s = 1; s <= n; s++) {
		if (num[s].counter == 2) {
			how_many++;
	//		cout << "process_counter : " << how_many << " ";
		}
//cout << endl;
	}

	cout << how_many << endl;
}