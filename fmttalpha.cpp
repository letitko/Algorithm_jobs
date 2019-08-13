#include <iostream>
using namespace std;

int main() {

	int x, y;
	cin >> x >> y;
	int sum = y - x;

	int flag = 0;
	int stand = 1;
	int plus = 1;

	for (int s = 1; s <= sum; s += 2*flag) {
		for (int t = s; t < s+2*stand; t++) {
			if (t > sum) { break; }
			if (t == s + stand) { plus+=1; }
			if (t == y - x) { cout << plus; }
		}
		plus++;
		flag++;
		stand++;
	}
}