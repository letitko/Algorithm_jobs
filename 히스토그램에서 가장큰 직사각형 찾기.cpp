#include <iostream>
using namespace std;

class flag {
public:
	int turn_on = 0;
	int idx_memorizer = 0;
};

class stack {
public:
	int data[100000];
	int how_many = 0;
	int capacity = 0;

	void create(int size) {
		capacity = size;
	}

	void push(int sample) {
		if (how_many >= capacity) { cout << "overflow" << endl; }
		else {
			data[how_many] = sample;
			how_many++;
		}
	}

	void pop() {
		if (how_many <= 0) { cout << "underflow" << endl; }
		else {
			data[how_many - 1] = 0;
			how_many--;
		}
	}

	int top() {
		if (how_many <= 0) { return -1; }
		else {
			return data[how_many - 1];
		}
	}
};

int main() {

	static int data[100000];
	int total;
	cin >> total;

	for (int s = 0; s < total; s++) {
		cin >> data[s];
	}

	flag hero;
	stack his;
	his.create(total);

	int current_height = 0;
	long long int current_square = 0;
	long long int biggest_square = 0;
	int end_idx = 0;
	int start_idx = 0;

	for (int idx = 0; idx < total;) { // idx == total이면 종료

		if (his.how_many == 0) { // 데이터가 애초에 없다면
			his.push(idx);
			idx += 1;
			if (idx == total) {
				current_height = data[his.top()];
				if (hero.turn_on == 1) {
					current_square = current_height * (total - 1 + 1);
				}
				else {
					current_square = current_height;
				}
				if (current_square > biggest_square) {
					biggest_square = current_square;
				}
			}
		}
		else if (his.how_many > 0) { // 데이터가 하나라도 있을때
			if (data[idx] >= data[his.top()]) { // 다음 올 데이터가 현재 탑데이터보다 크다면
				his.push(idx);
				idx += 1;
				if (idx == total) { // 추가했는데 이미 idx가 끝이라면
					while (his.how_many > 0) { // 종결보자
						current_height = data[his.top()];
						end_idx = total - 1;
						while (data[his.top()] == current_height) {
							start_idx = his.top();
							his.pop();
							if (his.how_many <= 0) {
								if (hero.turn_on == 1) {
									start_idx = hero.idx_memorizer;
								}
								break;
							}
							else {
								start_idx = his.top() + 1;
							}
						}
						current_square = (end_idx - start_idx + 1) * current_height;
						if (current_square > biggest_square) {
							biggest_square = current_square;
						}
					}
				}
			}
			else { // 다음 올 데이터가 현재 탑데이터 보다 작다면
				while (data[his.top()] > data[idx]) {
					current_height = data[his.top()];
					end_idx = idx - 1;
					while (data[his.top()] == current_height) {
						start_idx = his.top();
						his.pop();
						if (his.how_many <= 0) {
							//cout << "turned_on" << endl;
							if (hero.turn_on == 0) {
								hero.idx_memorizer = start_idx;
								hero.turn_on = 1;
								break;
							}
							else if (hero.turn_on == 1) {
								start_idx = hero.idx_memorizer;
								break;
							}
						}
						else {
							start_idx = his.top() + 1;
						}
					}
					current_square = (end_idx - start_idx + 1) * current_height;
					if (current_square > biggest_square) {
						biggest_square = current_square;
					}
				}
			}

		}

	}
	cout << biggest_square << endl;

}