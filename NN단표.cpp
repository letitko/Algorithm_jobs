#include <iostream>
#define LEN 100000 // 1<=n<=100000
using namespace std;

long long int n;
long long int total_num;
long long int dest_num;
long long int nice_value = 789789789789789789;

long long int how_many_less_than_mid(long long int mid) {
	long long int count = 0;
	for (int s = 1; s <= n; s++) {
		if ((mid / s) <= n) {
			count += mid / s;
		}
		else {
			count += n;
		}
	}
	//cout << "미드 값 : " << mid << " 카운트 수 : " << count << endl;
	return count;
}

bool is_nice_value_possible(long long int mid) { // nn단표 내부의 배수인가?
	for (long long int s = n; s >=1 ; s--) {
		if (mid % s == 0 && mid / s <= n) { // 나누어 떨어지고 몫이 n이하면 배수라는 것
			return 1;
		}
	}
	return 0;
}

long long int n_n_search(long long int s, long long int e) {

	if (s >= e) {
		if (s <= nice_value && is_nice_value_possible(s) == 1 && how_many_less_than_mid(s) >=dest_num ) { nice_value = s; } // 배수 중에는 있고
		return nice_value;
	}

	long long int mid = (s + e) / 2;

	if (how_many_less_than_mid(mid) < dest_num) {
		return n_n_search(mid+1,e);
	}
	else { //how_many_less_than_mid(mid) >= dest_num
		if (mid <= nice_value && is_nice_value_possible(mid) == 1) { nice_value = mid; }
		return n_n_search(s,mid-1);
	}
}

int main() {
	cin >> n;
	total_num = n * n;
	cin >> dest_num;

	cout << n_n_search(1, total_num);

}