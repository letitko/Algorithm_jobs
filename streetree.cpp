#include <iostream>
using namespace std;
#define LEN 100000

long long int gcd(long long int a, long long int b) { // 최대 공약수
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	static long long int trees[LEN + 1]; // 저장소
	static long long int difference[LEN + 1]; // 저장소
	int current_gcd;

	int total_trees;
	cin >> total_trees;
	
	for (int s = 1; s <= total_trees; s++) {
		cin >> trees[s];
	}

	for (int s = 1; s <= total_trees - 1; s++) {
		difference[s]=trees[s+1]-trees[s];
	}

	current_gcd = difference[1];

	for(int s=2;s<=total_trees;s++){
		current_gcd = gcd(current_gcd, difference[s]);
	}

	int total_dist = trees[total_trees] - trees[1];
	int result = total_dist / current_gcd -1 -(total_trees-2);
	cout << result;
}