#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

//       2---1
//       |  /|
//       | / |
//  5----4   3
//  |________/

// 5 6 -> n m
// 1 2
// 1 3
// 1 4
// 2 4
// 3 5
// 4 5

int main() {
	vector <int> nodes[MAX];

	int n, m;
	cin >> n >> m;
	for (int s = 0; s < m; s++) {
		int start, end;
		cin >> start >> end;
		nodes[start].push_back(end); // 해당 노드 리스트에 노드정보 삽입
		nodes[end].push_back(start); // 해당 노드 리스트에 노드정보 역으로 삽입
	}

	for (int s = 0; s <= n; s++) {
		cout << s << " : ";

		// node[s]의 리스트에 있는 요소를 출력한다
		for (int t = 1; t < nodes[s].size(); t++) {
			cout << nodes[s][t] << ' '; // s번째 노드의 배열 중 t인덱스에 대한 값 출력
			// 이것이 가능한 이유 nodes[s]자체가 배열의 이름이 되기대문에 X[idx]꼴에 대하여 X는 포인터에 담길 배열의 시작점주소라면
			// nodes[s]자체가 포인터에 담길 배열명이므로 X를 대체하여 X[t]의 꼴을 만들어 사용가능한 것이다.
		} cout << endl;

	}
}