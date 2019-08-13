#include <iostream>
#include <queue>
using namespace std;

bool virus_already[200000];
int total_town;
int first_blood;
int counter = 0;

queue <int> Queue;

void BFS() {

	virus_already[first_blood] = true;
	Queue.push(first_blood);

	while (!Queue.empty()) {

		int next = Queue.front();
		//cout << "next : " << next;
		Queue.pop();
		counter += 1;
		//cout << " counter : " << counter << endl;

		if (virus_already[next * 2] == false && next * 2 <= total_town) {
			virus_already[next * 2] = true;
			Queue.push(next * 2);
		}
		if (virus_already[next / 3] == false && next / 3 >= 1) {
			virus_already[next / 3] = true;
			Queue.push(next / 3);
		}
	}

	return;
}

int main() {
	cin >> total_town;
	cin >> first_blood;
	BFS();
	cout << total_town - counter << endl;
}