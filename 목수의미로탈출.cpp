#include <iostream>
#include <queue>
using namespace std;

// 시작점은 counter에서 제외
// st -> n-1,0
// ed -> 0, m-1

queue <int> Queue[2];
int map[1000][1000];
int n, m;
int map_cnt[1000][1000];
int map_cnt2[1000][1000];
bool possibility[1000][1000];
bool possibility2[1000][1000];
void maze_runner();
void maze_runner2();
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void find_sparrow(int arr[1000][1000], int arr2[1000][1000], int cross, int vertical) {

	int new_cross;
	int new_vertical;

	for (int s = 0; s < 4; s++) {

		new_cross = cross + dx[s];
		new_vertical = vertical + dy[s];

		if (new_vertical < m && new_cross > -1 && new_cross < n && new_vertical > -1) {
			if ((cross == n - 1 && vertical == 0) || (cross == 0 && vertical == m - 1)) {
				arr[new_cross][new_vertical] = 1;
				arr2[new_cross][new_vertical] = 1;
				break;
			}
			if (arr[new_cross][new_vertical] < arr[cross][vertical] && arr[new_cross][new_vertical] != 0 && map[new_cross][new_vertical] != 1) {
				arr[cross][vertical] = arr[new_cross][new_vertical] + 1;
			}

			if (arr2[new_cross][new_vertical] < arr2[cross][vertical] && arr2[new_cross][new_vertical] != 0 && map[new_cross][new_vertical] != 1) {
				arr2[cross][vertical] = arr2[new_cross][new_vertical] + 1;
			}
		}

	}

}

int main() {
	cin >> n >> m;

	for (int s = 0; s < n; s++) {
		for (int t = 0; t < m; t++) {
			cin >> map[s][t];
		}
	}

	maze_runner();
	maze_runner2();

	int gay_bar = 789789789;
	for (int s = 0; s < n; s++) {
		for (int t = 0; t < m; t++) {
			if (map[s][t] == 1) {
				map_cnt[s][t] = 789789789;
				map_cnt2[s][t] = 789789789;
				find_sparrow(map_cnt, map_cnt2, s, t);
			}
			if (map_cnt[s][t] + map_cnt2[s][t] < gay_bar && map_cnt[s][t] + map_cnt2[s][t] >= n + m - 2) {
				gay_bar = map_cnt[s][t] + map_cnt2[s][t];
			}
		}
	}

	cout << gay_bar << endl;
}

void maze_runner() {
	possibility[n - 1][0] = true;
	Queue[0].push(n - 1);
	Queue[1].push(0);
	map_cnt[n - 1][0] = 0;

	while (!Queue[0].empty() && !Queue[1].empty()) {
		int cross = Queue[0].front();
		int vertical = Queue[1].front();
		Queue[0].pop();
		Queue[1].pop();

		// 오
		if (vertical + 1 < m && possibility[cross][vertical + 1] == false && map[cross][vertical + 1] != 1) {
			Queue[0].push(cross);
			Queue[1].push(vertical + 1);
			possibility[cross][vertical + 1] = true;
			map_cnt[cross][vertical + 1] = map_cnt[cross][vertical] + 1;
		}
		// 상
		if (cross - 1 > -1 && possibility[cross - 1][vertical] == false && map[cross - 1][vertical] != 1) {
			Queue[0].push(cross - 1);
			Queue[1].push(vertical);
			possibility[cross - 1][vertical] = true;
			map_cnt[cross - 1][vertical] = map_cnt[cross][vertical] + 1;
		}
		// 하
		if (cross + 1 < n && possibility[cross + 1][vertical] == false && map[cross + 1][vertical] != 1) {
			Queue[0].push(cross + 1);
			Queue[1].push(vertical);
			possibility[cross + 1][vertical] = true;
			map_cnt[cross + 1][vertical] = map_cnt[cross][vertical] + 1;
		}
		// 좌
		if (vertical - 1 > -1 && possibility[cross][vertical - 1] == false && map[cross][vertical - 1] != 1) {
			Queue[0].push(cross);
			Queue[1].push(vertical - 1);
			possibility[cross][vertical - 1] = true;
			map_cnt[cross][vertical - 1] = map_cnt[cross][vertical] + 1;
		}

	}

	return;
}

void maze_runner2() {
	possibility2[0][m - 1] = true;
	Queue[0].push(0);
	Queue[1].push(m - 1);
	map_cnt2[0][m - 1] = 0;

	while (!Queue[0].empty() && !Queue[1].empty()) {
		int cross = Queue[0].front();
		int vertical = Queue[1].front();
		Queue[0].pop();
		Queue[1].pop();

		// 오
		if (vertical + 1 < m && possibility2[cross][vertical + 1] == false && map[cross][vertical + 1] != 1) {
			Queue[0].push(cross);
			Queue[1].push(vertical + 1);
			possibility2[cross][vertical + 1] = true;
			map_cnt2[cross][vertical + 1] = map_cnt2[cross][vertical] + 1;
		}
		// 상
		if (cross - 1 > -1 && possibility2[cross - 1][vertical] == false && map[cross - 1][vertical] != 1) {
			Queue[0].push(cross - 1);
			Queue[1].push(vertical);
			possibility2[cross - 1][vertical] = true;
			map_cnt2[cross - 1][vertical] = map_cnt2[cross][vertical] + 1;
		}
		// 하
		if (cross + 1 < n && possibility2[cross + 1][vertical] == false && map[cross + 1][vertical] != 1) {
			Queue[0].push(cross + 1);
			Queue[1].push(vertical);
			possibility2[cross + 1][vertical] = true;
			map_cnt2[cross + 1][vertical] = map_cnt2[cross][vertical] + 1;
		}
		// 좌
		if (vertical - 1 > -1 && possibility2[cross][vertical - 1] == false && map[cross][vertical - 1] != 1) {
			Queue[0].push(cross);
			Queue[1].push(vertical - 1);
			possibility2[cross][vertical - 1] = true;
			map_cnt2[cross][vertical - 1] = map_cnt2[cross][vertical] + 1;
		}

	}

	return;
}
