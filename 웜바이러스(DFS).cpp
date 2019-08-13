#include <iostream>
#include <vector>
using namespace std;

int virus_counter = 0;
vector <int> com[101];
bool com_ok[101];

void anchulsoo(int com_num) {
	com_ok[com_num] = true;
	virus_counter += 1;

	for (int s = 0; s < com[com_num].size(); s++) {
		int lined_com = com[com_num][s];
		if (com_ok[lined_com] == false) {
			anchulsoo(lined_com);
		}
	}

}

int main() {
	int total_com;
	cin >> total_com;
	int total_com_edges;
	cin >> total_com_edges;

	for (int s = 0; s < total_com_edges; s++) {
		int st, ed;
		cin >> st;
		cin >> ed;

		com[st].push_back(ed);
		com[ed].push_back(st);
	}

	anchulsoo(1);
	cout << virus_counter - 1 << endl;
}