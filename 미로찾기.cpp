#include <iostream>
#include <queue>
// #include <stack>
using namespace std;

// stack <int> Stack[2];
queue <int> Queue[2];
int map[1000][1000];
int n, m;
int map_cnt[1000][1000];
bool possibility[1000][1000];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

// 시작점은 counter에서 제외
// st -> n-1,0
// ed -> 0, m-1
void maze_runner() {
	int nx, ny;

	possibility[n - 1][0] = true;
	Queue[0].push(n-1);
	Queue[1].push(0);
	map_cnt[n - 1][0] = 0;

	while (!Queue[0].empty() && !Queue[1].empty()) {

		int cross = Queue[0].front();
		int vertical = Queue[1].front();
		Queue[0].pop();
		Queue[1].pop();

		/*for (int i = 0; i < 4; i++) {
			nx = cross + dx[i];
			ny = vertical + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m || possibility[nx][ny] || map[nx][ny] == 1) continue;


		}*/

		// 오
		if (vertical + 1 < m && possibility[cross][vertical + 1] == false && map[cross][vertical + 1] != 1) {
			Queue[0].push(cross);
			Queue[1].push(vertical+1);
			possibility[cross][vertical+1]=true;
			map_cnt[cross][vertical + 1] = map_cnt[cross][vertical] + 1;
		}
		// 상
		if (cross - 1 > -1 && possibility[cross - 1][vertical] == false && map[cross - 1][vertical] != 1) {
			Queue[0].push(cross-1);
			Queue[1].push(vertical);
			possibility[cross-1][vertical] = true;
			map_cnt[cross-1][vertical] = map_cnt[cross][vertical] + 1;
		}
		// 하
		if (cross + 1 < n && possibility[cross + 1][vertical] == false && map[cross + 1][vertical] != 1) {
			Queue[0].push(cross +1);
			Queue[1].push(vertical);
			possibility[cross + 1][vertical] = true;
			map_cnt[cross + 1][vertical] = map_cnt[cross][vertical] + 1;
		}
		// 좌
		if (vertical - 1 > -1 && possibility[cross][vertical - 1] == false && map[cross][vertical - 1] != 1) {
			Queue[0].push(cross);
			Queue[1].push(vertical-1);
			possibility[cross][vertical-1] = true;
			map_cnt[cross][vertical-1] = map_cnt[cross][vertical] + 1;
		}

	}

	return;
}

int main() {
	cin >> n >> m;

	for (int s = 0; s < n; s++) {
		for (int t = 0; t < m; t++) {
			cin >> map[s][t];
		}
	}

	maze_runner();
	cout << map_cnt[0][m - 1] << endl;
}
