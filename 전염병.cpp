#include <iostream>
using namespace std;

class circle_queue {
public:
	int data[100000];
	int f;
	int r;
	int capacity;
	int how_many;

	void create(int s) {
		capacity = s;
		f = 0;
		r = 0;
		how_many = 0;
	}

	void push(int s) {
		if (how_many >= capacity) {
			cout << "Overflow" << endl;
		}
		else {
			data[r] = s;
			r += 1;
			how_many += 1;
			if (r == capacity) {
				r = 0;
			}
		}
	}

	void pop() {
		if (how_many <= 0) {
			cout << "Underflow" << endl;
		}
		else {
			data[f] = 0;
			f += 1;
			how_many -= 1;
			if (f == capacity) {
				f = 0;
			}
		}
	}

	int front() {

		if (how_many <= 0) {
			return -1;
		}
		else {
			return data[f];
		}
	}

};

class survive {
public:
	int flag = 1;
};

void find_survive(survive * surviver, circle_queue *towns, int blood, int total_town) {

	if (blood >= 1 && blood <= total_town) {
		if (surviver[blood].flag == 1) {
			surviver[blood].flag = 0;
			towns->push(blood);
			//	cout << towns->data[towns->r-1] << ' ' <<towns->how_many << endl;
		}
		else { return; } // 이거없으면 무한연산 들어가서 런타임 오류나옴
		find_survive(surviver, towns, blood * 2, total_town);
		find_survive(surviver, towns, blood / 3, total_town);
	}
	else { return; }

}

int main() {

	static survive town_flag[100001];

	circle_queue towns;
	int total_town; // 마을 개수
	cin >> total_town;
	towns.create(total_town);

	int first_blood; // 첫번째 사망자
	cin >> first_blood;

	find_survive(town_flag, &towns, first_blood, total_town);

	cout << total_town - towns.how_many << endl;
}