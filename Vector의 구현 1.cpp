#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> smith(5, 18); // vector 스미스의 크기를 int형으로 5칸 만들고 그 값을 전부 18로 초기화 시킨다.
	for (int s = 0; s < 5; s++) {
		smith[s] = s;
	}
	smith.push_back(6);
	for (int s = 0; s< 6; s++){
		cout << smith[s] << ' ';
	}
}