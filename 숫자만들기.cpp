#include <iostream>
#define LEN 100000
using namespace std;

long long int how_to_make_num[LEN + 1];

int main() {

	int n;
	int m = 3;
	cin >> n;
	// ��� ������ ���� 1,2,3�϶�
	// ���� 1�ΰ�� : n[1] = 1; // ���� 1�ΰ��
	// ���� 2�ΰ�� : n[2] = n[1] + 1; // ���� 1�ΰ�� , 2�ΰ��
	// ���� 3�ΰ�� : n[3] = n[2] + n[1] +1; // ���� 1�ΰ�� , ���� 2�ΰ��, ���� 3�ΰ��
	// ���� 4�ΰ�� : n[4] = n[3] + n[2] + n[1]; // ���� 1�ΰ��, ���� 2�ΰ��, ���� 3�ΰ��
	// ���� n�ΰ�� : n[n] = n[n-1] + n[n-2] + n[n-3];
	how_to_make_num[1] = 1;
	long long int sum = 0;
	for (int s = 2; s <= m; s++) {
		sum += how_to_make_num[s - 1];
		how_to_make_num[s] = sum + 1;
	}
	for (int s = m + 1; s <= n; s++) {
		for (int t = s - m; t < s; t++) {
			how_to_make_num[s] += (how_to_make_num[t]) % 1000007;
		}
	}

	cout << how_to_make_num[n] % 1000007 << endl;
}