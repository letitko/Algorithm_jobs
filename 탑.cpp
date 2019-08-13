#include <iostream>
#include <string.h>
using namespace std;

class stack {
public:
	long long int data [500000]; // 데이터량
	long long int how_many = 0; // 원소개수
	long long int size = 0; // 최대수용개수
	void create(int s) { // 최대수용수한정
		size = s;
	}

	void push(long long int insert_data) {
		if (how_many >= size) {
			cout << "Overflow" << endl;
		}
		else {
			data[how_many] = insert_data; // 인덱스기준 데이터 입력
			how_many++; // 개수증가
		}
	}

	void pop() {
		if (how_many <= 0) {
			cout << "Underflow" << endl;
		}
		else {
			data[how_many - 1] = 0; // 인덱스기준 데이터하나 삭제
			how_many--; // 개수감소
		}
	}

	long long int top() {
		// 데이터가 없을 경우  -1 리턴
		if (how_many <= 0) {
			return -1;
		}
		else {
			return data[how_many - 1];// 인덱스기준 스택 최상위 데이터하나 출력
		}
	}

};

int main() {
	stack top; // 스택 생성
	stack top_idx;
	top.create(500000); // 스택 데이터 지정
	top_idx.create(500000); // 스택 데이터 지정
	long long int total; // 탑의 수
	long long int height; // 현재 높이
	long long int cnt = 0; // idx 카운터
	cin >> total;

	top.push(0);
	top_idx.push(0);

	for (int s = 0; s < total; s++) {
		cin >> height; // 현재높이 입력

		while (height >= top.top()) {
			if (top.how_many <= 0) { break;	}
			top.pop(); // 자신보다 높은 idx를 제외한 불 필요 요소 제거
			top_idx.pop();
		}

		if (top.how_many<=0) { // 현 데이터의 수가 0 이라면 
			cout << "0" << ' '; // 0을 출력한다
			cnt += 1; // idx백업용 idx
			top.push(height); // 현재의 데이터를 입력하고
			top_idx.push(cnt);
		}

		else { // 현 데이터의 수가 0보다 크다는건
				cout << top_idx.top() << ' ';
				top.push(height);
				cnt += 1;
				top_idx.push(cnt);
		}
	}

}
