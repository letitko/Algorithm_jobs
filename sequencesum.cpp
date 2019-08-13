#include <iostream>
using namespace std;
#define LEN 1000

int main() {

	int num[LEN + 1][LEN + 1] = { 0, };
	int sum = 0;
	int yoso[LEN + 1] = { 0, };

	int N;
	cin >> N;
	for (int s = 1; s <= N; s++) {
		for (int t = 1; t <= N; t++) {
			cin >> num[s][t];
		}
	} // �����Ͱ� �ް�

	for (int s = 1; s <= N; s++) {
		for (int t = 1; t <= N; t++) {
			sum += num[s][t];
		}
	} // ���� �ް�

	int sum_of_each_yoso = sum / 2 / (N - 1);

	int each_hang_sum[LEN + 1] = { 0, };

	// �� ������� ����
	for (int s = 1; s <= N; s++) {
		for(int t=1; t<=N; t++){
			each_hang_sum[s] += num[s][t];
		}
	}

	// �� ��Ҹ� ���غ���
	for (int s = 1; s <= N; s++){
		yoso[s] = (sum_of_each_yoso - each_hang_sum[s])/(N-2);
	}

	// �� ��� ���
	for (int t = 1; t <= N; t++) {
		cout << yoso[t] * -1 << " ";

	}
	cout << endl;
	return 0;
}