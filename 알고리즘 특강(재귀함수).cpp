#include <iostream>
using namespace std;

// 예제 1 : 2진수 출력하기
/*
void bin(int x) {
	if (x <= 1) { cout << 1 << endl;  return; }
	else {
		bin(x / 2);
		cout << x % 2 << endl;
	}
	

}

int main() {
	int n;
	cin >> n;
	bin(n);
}
*/

// 예제 2 : 역반복 출력하기
/*
void reverse(int n, int dest)	{ // 대칭성 여부를 파악하는 유형
	if (n == dest) {
		cout << dest;
		return;
	}
	else {
		cout << n; // 예: dest가 5라면 123454321일때 5를 기준으로 대칭출력이 나오게 된다.
		reverse(n + 1, dest);
		cout << n; // 예: dest가 5라면 123454321일때 5를 기준으로 대칭출력이 나오게 된다.
	}
}

int main() {
	int dest;
	cin >> dest;
	reverse(1,dest);
}
*/

// 예제 3 : mountain
/*
// 설계기법 매개변수 : 산의 높이
void mountain(int height) { // 준, 트리구조
	// 4 -> 3 -> 2 ->1
	// 1에 도착하면 자기자신 출력
	// 2에 도착하면 1로 내려갔다 다시 2로 올라옴
	// 3도 마찬가지로 반복
	// 4또한 반복

	if (height == 1) {
		cout << 1; return;
	}
	else {
		mountain(height - 1);
		cout << height;
		mountain(height -1);
	}
}

int main() {
	int n;
	cin >> n;
	mountain(n);
}
*/

// 예제 4 : tobin
// 매개변수 : 만들어진 수열의 길이와 수열의 1의 개수
// 기저조건 : 만들어진 수열의 길이가 N이라면 탈출

int arr[30 + 1];

void tobin(int dest, int cnt, int idx, int how_many) {
	if (how_many >= 3) { return; }
	if (cnt == dest+1) {
		if (how_many == 2) {
			for (int s = 0; s <= 3; s++) {
				cout << arr[s];
			}
			cout << endl;
		}
		return;
	}
	for (int s = 1; s >= 0; s--) {
		arr[idx] = s;
		if(s==1) {
		tobin(dest,cnt +1,idx+1,how_many+1);
		}
		else {
		tobin(dest, cnt + 1, idx + 1, how_many);
		}
	}
}

int main() {
	int dest;
	int cnt = 0;
	int idx = 0;
	int how_many = 0;
	cin >> dest;
	tobin(dest, cnt, idx, how_many);
}

// 예제5. division
/*
// 매개변수 : 총합
// 탈출구 : 총합이N일때, 총합이 N보다 클때

int arr[30];
int n; // n은 초기에 주어지는 값

int division(int sum, int len, int dest) {
	if (sum == dest) { // 기저조건 탈출 및 출력
		for(int s=0;s<len;s++){
			cout << arr[s];
		}
		cout << endl;
		return 0;
	}
	if (sum > dest) { // 애초에 안될것 제외
		return 0;
	}
	for (int i = n - 1; i >= 1; i--) {
		arr[len] = i;
		division(sum + i, len + i, dest);
	}
	// 미완성 코드 : 왜? 중복조건 필터링이 없기때문에
}

int main() {
	cin >> n;
	dest= n;
	division(0,0,dest);
*/