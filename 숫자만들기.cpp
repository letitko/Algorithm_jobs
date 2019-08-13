#include <iostream>
#define LEN 100000
using namespace std;

long long int how_to_make_num[LEN + 1];

int main() {

	int n;
	int m = 3;
	cin >> n;
	// 사용 가능한 수가 1,2,3일때
	// 합이 1인경우 : n[1] = 1; // 끝이 1인경우
	// 합이 2인경우 : n[2] = n[1] + 1; // 끝이 1인경우 , 2인경우
	// 합이 3인경우 : n[3] = n[2] + n[1] +1; // 끝이 1인경우 , 끝이 2인경우, 끝이 3인경우
	// 합이 4인경우 : n[4] = n[3] + n[2] + n[1]; // 끝이 1인경우, 끝이 2인경우, 끝이 3인경우
	// 합이 n인경우 : n[n] = n[n-1] + n[n-2] + n[n-3];
	how_to_make_num[1] = 1;
	long long int sum = 0;
	for (int s = 2; s <= m; s++) {
		sum += how_to_make_num[s - 1];
		how_to_make_num[s] = sum + 1;
	}
	for (int s = m + 1; s <= n; s++) {
		for (int t = s - m; t < s; t++) {
			how_to_make_num[s] += (how_to_make_num[t]) % 1000007;
		}
	}

	cout << how_to_make_num[n] % 1000007 << endl;
}