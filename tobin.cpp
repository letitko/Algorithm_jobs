#include <iostream>
using namespace std;
#define LEN 30 // 30자리 까지
#define K_LEN 7 // 7개 까지

void recur(int * arr, int len, int idx, int how_many, int counter) {

	if (counter > how_many) { return; }

	if (idx == len) { // 기저, 탈출 조건
			if(counter == how_many){
				for (int index = 0; index < len; index++) {
				cout << arr[index];
				}
				cout << endl;
			}
		return;
	}

	for (int i = 1; i >= 0; i--) {
		arr[idx] = i;
		if (i == 1)  {	recur(arr, len, idx + 1, how_many, counter+1);}
		else {recur(arr, len, idx + 1, how_many, counter);}
	}
}

int main() {
	int len;
	int counter = 0;
	int how_many;
	int arr[LEN];
	cin >> len >> how_many;
	recur(arr, len, 0, how_many,0);
}

/*
1. 탐색
1111
1110
1101
1100
1011
1010
1001
1000
.
.
0000

2. 정답 고르기
1100
1010
1001
0110
0101
0011

(3. 가지치기)


void recur()
{
	if() return; // 애초에 불가능한 노드 전부 필터링

	if() // 정답 추리를위한 기저 조건
	{
		if() print();

		return;
	}

	for() // 처리 및 탐색
	{
		/////
		recur();
	}
}
*/