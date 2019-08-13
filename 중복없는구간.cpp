#include <iostream>
#include <string.h>
using namespace std;

int nice_value = 1;
int nums[100005];
int possibility[100005];
int total_num;
int what_is_the_best = 0;

bool is_possible(int dest) {

	int new_hero = 0;
	for (int s = 0; s < dest; s++) {
		if (possibility[nums[s]] == 0) {
			new_hero += 1;
		}
		if (new_hero == dest) {
			return 1;
		}
		possibility[nums[s]] += 1;
	}

	int idx = 0;

	for (int s = dest; s < total_num; s++) {
		if (possibility[nums[idx]] == 1) {
			new_hero -= 1;
		}
		possibility[nums[idx]] -= 1;
		idx += 1;

		if (possibility[nums[s]] == 0) {
			new_hero += 1;
		}
		possibility[nums[s]] += 1;

		if (new_hero == dest) {
			return 1;
		}
	}
	return 0;
}

int parametric_search(int s, int e) {
	memset(possibility, 0, sizeof(possibility));
	int mid = (s + e) / 2;
	//	cout << s << ' ' << mid << ' ' << e << ' ' << endl;
	if (s >= e) {
		if (is_possible(s) == 1 && s > nice_value) { nice_value = s; }
		return nice_value;
	}
	else {

		if (is_possible(mid) == 0) { // 안돼면 더 적은 연속 범위에서 찾아봐
			//cout << nice_value << endl;
			return (parametric_search(s, mid));
		}
		else { // 돼면 더 큰 범위에 도전해봐
			if (mid > nice_value) { nice_value = mid; }
			//cout << nice_value << endl;
			return (parametric_search(mid + 1, e));
		}
	}

}

int main() {

	cin >> total_num;
	for (int s = 0; s < total_num; s++) {
		cin >> nums[s];
	}
	for (int s = 0; s < total_num; s++) {
		if (nums[s] > what_is_the_best) {
			what_is_the_best = nums[s];
		}
	}

	parametric_search(1, what_is_the_best);
	cout << nice_value << endl;

}