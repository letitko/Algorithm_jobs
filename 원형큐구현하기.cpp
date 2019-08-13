#include <iostream>
using namespace std;

class op {
public:
	int main;
	int sub;
};

class circle_queue {
public:
	int data[101];
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

int main() {
	// 1 push
	// 2 pop
	// 3 front

	int size_of_queue;
	cin >> size_of_queue;

	int total_op;
	cin >> total_op;

	op operators[1000];

	for (int s = 0; s < total_op; s++) {
		int flag = 0;
		cin >> flag;
		if (flag == 1) {
			operators[s].main = flag;
			cin >> operators[s].sub;
		}
		else {
			operators[s].main = flag;
		}
	}

	circle_queue q;
	q.create(size_of_queue);

	for (int s = 0; s < total_op; s++) {
		if (operators[s].main == 1) {
			q.push(operators[s].sub);
		}
		else if (operators[s].main == 2) {
			q.pop();
		}
		else {
			if (q.front() == -1) {
				cout << "NULL" << endl;
			}
			else { cout << q.front() << endl; }
		}
	}

	return 0;
}