#include <iostream>
using namespace std;
// 97 = 'a'

bool del_occasion(char temp[], char arr, int n_idx) {
	
	for(int s=0;s<n_idx;s++){
		if (temp[s] == arr) {
			return 1;
		}
	}
	return 0;
}

void recursion(char arr[], char temp[], int dest_idx, int n_idx, int count) {


	if (n_idx == count) { // 기저 탈출 조건
		for (int s = 0; s < count; s++) {
			cout << temp[s];
		}
		cout << endl; return;
	}

	for (int idx = 0; idx < dest_idx; idx++) { // 출력하기
		if(del_occasion(temp, arr[idx], n_idx)) { continue; }	// 가지치기
		temp[n_idx] = arr[idx];
		recursion(arr, temp, dest_idx, n_idx + 1, count);
	}


}



int main() {

	char arr[26]; // 배열
	char temp[26]; // 임시 저장소
	int idx = 0; // 인덱스
	for (int s = 97; s <= 97 + 25; s++) {
		arr[idx] = s;
		idx++;
	} //알파벳 입력

	int n_idx = 0;

	int dest_idx;
	int count;

	cin >> dest_idx;
	cin >> count;

	recursion(arr, temp, dest_idx, n_idx, count);
	return 0;
}