#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector <int> arr;

	arr.push_back(1); // 배열에 자리하나 늘리고 데이터 1 저장해라
	arr.push_back(2); // 배열에 자리하나 늘리고 데이터 2 저장해라
	arr.push_back(3); // 배열에 자리하나 늘리고 데이터 3 저장해라

	cout << arr[0] << arr[1] << arr[2] << endl;

	arr.pop_back(); // 배열 맨 뒷자리 데이터 하나 버리고 크기 하나 줄여라

	cout << arr.size() << endl; // 출력 크기 2

	arr.resize(10, 5);

	for (int s = 0; s < arr.size(); s++) {
		cout << arr[s] << ' ';
	} cout << endl; // 1 2 5 5 5 5 5 5 5 5 출력

	arr.resize(5); // 크기를 10에서 5로 다시 줄여본다

	for (int s = 0; s < arr.size(); s++) {
		cout << arr[s] << ' ';
	} cout << endl; // 1 2 5 5 5 출력

	return 0;
}