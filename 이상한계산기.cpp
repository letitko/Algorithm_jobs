#include <iostream>
#include <queue>
#define MAX 99999
using namespace std;

queue <int> Queue;
bool possibility[900000];
int num_cnt[900000];
int dest;
int f_counter = 789789789;

void BFS(){

	possibility[0] = true;
	possibility[1] = true;
	Queue.push(1);
	num_cnt[0] = 0;
	num_cnt[1] = 0;

	while(!Queue.empty()){
		
		int new_data = Queue.front();

		if (new_data >= (dest + 1) * 8) {
			Queue.pop();
			continue;
		} // 거를 조건

		Queue.pop();
		//cout << "n_d : " << new_data << " cnt : " << num_cnt[new_data] << endl;

		if (new_data == dest) {
			if (num_cnt[new_data] < f_counter) {
				f_counter = num_cnt[new_data];
				break;
			}
		}
		
		if (possibility[new_data * 2] == false) {
			possibility[new_data * 2] = true;
			Queue.push(new_data * 2);
			num_cnt[new_data * 2] = num_cnt[new_data] + 1;
		}
		if (possibility[new_data / 3] == false) {
			possibility[new_data / 3] = true;
			Queue.push(new_data / 3);
			num_cnt[new_data / 3] = num_cnt[new_data] + 1;
		}
	}

	return;
}

int main() {
	cin >> dest;

	if (dest == 1) {
		cout << 0 << endl;
	}
	else {
		BFS();
		cout << f_counter << endl;
	}
}