#include <iostream>
#define LEN 100
using namespace std;

// 끝이 세워진 형태로 끝나는 경우, 끝이 누워진 형태로 끝나는 경우에 대한 합이 T(N)이 된다.
// 즉, T(N) = T(N-1) +T(N-2)

int temp[LEN + 1];

int main() {

	temp[1] = 1;
	temp[2] = 2;
	for (int s = 3; s <= LEN; s++) {
		temp[s] = (temp[s - 1] + temp[s - 2]) % 1000007;
	}

	int num;
	cin >> num;
	cout << temp[num];

}