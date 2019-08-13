#include <iostream>
using namespace std;
#define MAP_SIZE 101

class ground {
public:
	int whos = 0;
};

class color {
public:
	int x=0;
	int y=0;
	int width=0;
	int height=0;
};

void mapping(ground map[MAP_SIZE + 1][MAP_SIZE + 1], color paper[MAP_SIZE], int x, int y, int width, int height, int paper_num) {
	for (int s = x; s <= x+(width-1); s++) {
		for (int t = y; t <= y+(height-1); t++) {
			map[s][t].whos = paper_num;
		}
	}
}

int main() {
	ground map[MAP_SIZE + 1][MAP_SIZE + 1];
	color paper[MAP_SIZE];
	int total_paper;
	cin >> total_paper;

	for (int t = 1; t <= total_paper; t++) {
		cin >> paper[t].x;
		cin >> paper[t].y;
		cin >> paper[t].width;
		cin >> paper[t].height;
	}

	for (int paper_num = 1; paper_num <= total_paper; paper_num++) {
		mapping(map, paper, paper[paper_num].x, paper[paper_num].y, paper[paper_num].width, paper[paper_num].height, paper_num);
	}

	for (int paper_num = 1; paper_num <= total_paper; paper_num++) {
		int counter = 0;
		for (int s = 0; s <= MAP_SIZE; s++) {
			for (int t = 0; t <= MAP_SIZE; t++) {
				if (map[s][t].whos == paper_num) {
					counter++;
				}
			}
		}
		cout << counter << endl;
	}
}
