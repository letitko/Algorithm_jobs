#include <iostream>
#define TO_LEN 7
#define LEN 300000
using namespace std;

	int nu[LEN * 2 + 2] = { 0, };
	int nu_2[123456 + 1] = { 0, };

int main() {

	// �����佺�׳׽�
	// ���ʿ� 2�̻��� ������ �Ҽ���� �Ǵ��ϰ� prime��ǥ�� 0�̶��ϸ�
	for (int s = 2; s*s <= LEN; s++) { // �������� �ְ���ǥ�� ���϶��
		if (nu[s] == 1) { continue; }
		for (int t = s * s; t <= LEN; t += s) { // �Ҽ��� ����� ��� �Ҽ��� �ƴϴ�.
			nu[t] = 1; // 1�� ǥ��Ȱ��� �Ҽ��� �ƴϴ�
		}
	}

	int temp;
	int idx = 0;
	while(1){
		cin >> temp;
		if (temp == 0) { break; }
		nu_2[idx] = temp;
		idx++;
	}



	int k = 0;
	while(1) {
		if (k == idx) { break; }
		int cnt = 0;
		for (int s = nu_2[k] + 1; s <= nu_2[k] * 2; s++) {
			if (nu[s] == 0) { cnt++; }
		}
		cout << cnt << endl;
		k++;
	}

}