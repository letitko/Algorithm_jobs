#include <iostream>
using namespace std;
// 기준수의 10007로 나눈수는 몫+나머지 로 구성된다
// 기준수*기준수의 구성은 몫*몫 + 2(몫*나머지) + 나머지*나머지가 있다
// 몫이란건 어차피 10007로 수가 나뉘어졌을때 사라질 부분이다.
// 즉 나머지 부분만 미리 구해서 그값들을 곱하여 10007로 나눈후의 나머지만 
// 반환해주면 된다.
int recursive_multiply(long long int total_time, int n) {

	if (total_time <= 1) {
		return n % 10007;
	}

	long long int process;
	long long int extra;

	if (total_time % 2 != 0) {
		process = recursive_multiply(total_time / 2, n);
		extra = n;
	}
	else {
		process = recursive_multiply(total_time / 2, n);
		extra = 1;
	}

	long long int sum = (process % 10007) * (process % 10007) * extra;

	return sum % 10007;
}

int main() {
	int n;
	long long int m; // 1~1000000000000000000
	cin >> n;
	cin >> m;
	int result = recursive_multiply(m, n);
	cout << result;
}