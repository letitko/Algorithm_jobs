#include <iostream>
using namespace std;

int mineral[1002][1002];
int n_way;
int m_way;

int main() {

	cin >> n_way;
	cin >> m_way;

	for (int s = 1; s <= n_way; s++) {
		for (int t = 1; t <= m_way; t++) {
			cin >> mineral[s][t];
		}
	}

	for (int s = 1; s <= n_way; s++) {
		for (int t = 1; t <= m_way; t++) {
			mineral[s][t] = ((mineral[s][t - 1] > mineral[s - 1][t] ? mineral[s][t - 1] : mineral[s - 1][t]) + (mineral[s][t]));
		}
	}

	cout << mineral[n_way][m_way] << endl;

	return 0;
}