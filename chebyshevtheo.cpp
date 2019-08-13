#include <iostream>
#define TO_LEN 7
#define LEN 300000
using namespace std;

	int nu[LEN * 2 + 2] = { 0, };
	int nu_2[123456 + 1] = { 0, };

int main() {

	// 에라토스테네스
	// 애초에 2이상의 모든수를 소수라고 판단하고 prime지표를 0이라하면
	for (int s = 2; s*s <= LEN; s++) { // 제곱수가 최고지표수 이하라면
		if (nu[s] == 1) { continue; }
		for (int t = s * s; t <= LEN; t += s) { // 소수의 배수는 모두 소수가 아니다.
			nu[t] = 1; // 1로 표기된것은 소수가 아니다
		}
	}

	int temp;
	int idx = 0;
	while(1){
		cin >> temp;
		if (temp == 0) { break; }
		nu_2[idx] = temp;
		idx++;
	}



	int k = 0;
	while(1) {
		if (k == idx) { break; }
		int cnt = 0;
		for (int s = nu_2[k] + 1; s <= nu_2[k] * 2; s++) {
			if (nu[s] == 0) { cnt++; }
		}
		cout << cnt << endl;
		k++;
	}

}