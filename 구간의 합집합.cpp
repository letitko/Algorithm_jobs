#include <iostream>
using namespace std;

long long int stand_1;
long long int stand_2;
long long int total_sample;
long long int dest;

class Quest {
public:
	long long int st;
	long long int ed;
};

Quest sample[10000];

long long int is_possible(long long int num) {
	long long int cnt = 0;
	for (long long int s = 0; s < total_sample; s++) {
		if (sample[s].ed < num) {
			cnt += (sample[s].ed - sample[s].st + 1);
		}
		else if (sample[s].st < num && num <= sample[s].ed) {
			cnt += (num - sample[s].st);
		}
	}
	return cnt;
}

long long int is_really_possible(long long int num) {
	long long int cnt = 0;
	for (long long int s = 0; s < total_sample; s++) {
		if (sample[s].ed < num + 1) {
			cnt += (sample[s].ed - sample[s].st + 1);
		}
		else if (sample[s].st < num + 1 && num + 1 <= sample[s].ed) {
			cnt += (num + 1 - sample[s].st);
		}
	}
	return cnt;
}

long long int find_term(long long int s, long long int e) {

	if (s >= e) {
		return s;
	}
	else {

		long long int mid = (s + e) / 2;
		stand_1 = is_possible(mid);
		stand_2 = is_really_possible(mid);

		if (stand_1 >= dest) {
			return find_term(s, mid - 1);
		}
		else if (dest > stand_2) {
			return find_term(mid + 1, e);
		}
		else { // stand_1 < dest <= stand_2
			return mid;
		}


	}
}

int main() {

	cin >> total_sample;
	for (long long int s = 0; s < total_sample; s++) {
		cin >> sample[s].st >> sample[s].ed;
	}
	cin >> dest;
	dest += 1;

	cout << find_term(1, 1000000000);
}