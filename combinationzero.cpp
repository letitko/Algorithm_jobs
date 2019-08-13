#include <iostream>
using namespace std;
#define LEN

class cou {
public:
	int two=0;
	int five = 0;
};

int main() {

	long long int n;
	long long int m;

	cou counter_top;
	cou counter_bot;
	cou counter_bot2;

	cin >> n >> m;

	for (int s = 2; s <= n; s++) {
		int num = s;
		while (num % 5 == 0) {
			counter_top.five++;
			num /= 5;
		}
		while (num % 2 == 0) {
			counter_top.two++;
			num /= 2;
		}
	}

	for (int s = 2; s <= m; s++) {
		int num = s;
		while (num % 5 == 0) {
			counter_bot.five++;
			num /= 5;
		}
		while (num % 2 == 0) {
			counter_bot.two++;
			num /= 2;
		}
	}

	for (int s = 2; s <= n-m; s++) {
		int num = s;
		while (num % 5 == 0) {
			counter_bot2.five++;
			num /= 5;
		}
		while (num % 2 == 0) {
			counter_bot2.two++;
			num /= 2;
		}
	}

	int re_five= counter_top.five - counter_bot.five - counter_bot2.five;
	int re_two = counter_top.two - counter_bot.two - counter_bot2.two;
	int result = (re_five >= re_two) ? re_two : re_five;

	cout << result << endl;
}