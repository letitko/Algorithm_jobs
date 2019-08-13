#include <iostream>
using namespace std;
// ���ؼ��� 10007�� �������� ��+������ �� �����ȴ�
// ���ؼ�*���ؼ��� ������ ��*�� + 2(��*������) + ������*�������� �ִ�
// ���̶��� ������ 10007�� ���� ������������ ����� �κ��̴�.
// �� ������ �κи� �̸� ���ؼ� �װ����� ���Ͽ� 10007�� �������� �������� 
// ��ȯ���ָ� �ȴ�.
int recursive_multiply(long long int total_time, int n) {

	if (total_time <= 1) {
		return n % 10007;
	}

	long long int process;
	long long int extra;

	if (total_time % 2 != 0) {
		process = recursive_multiply(total_time / 2, n);
		extra = n;
	}
	else {
		process = recursive_multiply(total_time / 2, n);
		extra = 1;
	}

	long long int sum = (process % 10007) * (process % 10007) * extra;

	return sum % 10007;
}

int main() {
	int n;
	long long int m; // 1~1000000000000000000
	cin >> n;
	cin >> m;
	int result = recursive_multiply(m, n);
	cout << result;
}