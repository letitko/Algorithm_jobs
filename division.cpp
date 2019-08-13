#include <iostream>
using namespace std;

void division(int num[], int value ,int idx, int sum, int dest,int*counter) {

	if (sum > dest) { // 가지치기
		return;
	}
	else if (sum == dest) {
		// 기저조건
		*counter+=1;
		for (int op = 0; op <= idx-1; op++) {
			if (op == idx - 1) { cout << num[op]; continue; }
			cout << num[op] << "+";
		}
		cout << endl;
		return;
	}

	for(int s=value;s>=1;s--){
		num[idx] = s;
		division(num, s, idx + 1, sum + s, dest, counter);
	}

}

int main() {
	int counter = 0;
	int num[21];
	int total;
	cin >> total;
	division(num, total - 1, 0, 0, total, &counter);
	cout << counter;
}