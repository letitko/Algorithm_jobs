#include <iostream>
using namespace std;

// ���� 1 : 2���� ����ϱ�
/*
void bin(int x) {
	if (x <= 1) { cout << 1 << endl;  return; }
	else {
		bin(x / 2);
		cout << x % 2 << endl;
	}
	

}

int main() {
	int n;
	cin >> n;
	bin(n);
}
*/

// ���� 2 : ���ݺ� ����ϱ�
/*
void reverse(int n, int dest)	{ // ��Ī�� ���θ� �ľ��ϴ� ����
	if (n == dest) {
		cout << dest;
		return;
	}
	else {
		cout << n; // ��: dest�� 5��� 123454321�϶� 5�� �������� ��Ī����� ������ �ȴ�.
		reverse(n + 1, dest);
		cout << n; // ��: dest�� 5��� 123454321�϶� 5�� �������� ��Ī����� ������ �ȴ�.
	}
}

int main() {
	int dest;
	cin >> dest;
	reverse(1,dest);
}
*/

// ���� 3 : mountain
/*
// ������ �Ű����� : ���� ����
void mountain(int height) { // ��, Ʈ������
	// 4 -> 3 -> 2 ->1
	// 1�� �����ϸ� �ڱ��ڽ� ���
	// 2�� �����ϸ� 1�� �������� �ٽ� 2�� �ö��
	// 3�� ���������� �ݺ�
	// 4���� �ݺ�

	if (height == 1) {
		cout << 1; return;
	}
	else {
		mountain(height - 1);
		cout << height;
		mountain(height -1);
	}
}

int main() {
	int n;
	cin >> n;
	mountain(n);
}
*/

// ���� 4 : tobin
// �Ű����� : ������� ������ ���̿� ������ 1�� ����
// �������� : ������� ������ ���̰� N�̶�� Ż��

int arr[30 + 1];

void tobin(int dest, int cnt, int idx, int how_many) {
	if (how_many >= 3) { return; }
	if (cnt == dest+1) {
		if (how_many == 2) {
			for (int s = 0; s <= 3; s++) {
				cout << arr[s];
			}
			cout << endl;
		}
		return;
	}
	for (int s = 1; s >= 0; s--) {
		arr[idx] = s;
		if(s==1) {
		tobin(dest,cnt +1,idx+1,how_many+1);
		}
		else {
		tobin(dest, cnt + 1, idx + 1, how_many);
		}
	}
}

int main() {
	int dest;
	int cnt = 0;
	int idx = 0;
	int how_many = 0;
	cin >> dest;
	tobin(dest, cnt, idx, how_many);
}

// ����5. division
/*
// �Ű����� : ����
// Ż�ⱸ : ������N�϶�, ������ N���� Ŭ��

int arr[30];
int n; // n�� �ʱ⿡ �־����� ��

int division(int sum, int len, int dest) {
	if (sum == dest) { // �������� Ż�� �� ���
		for(int s=0;s<len;s++){
			cout << arr[s];
		}
		cout << endl;
		return 0;
	}
	if (sum > dest) { // ���ʿ� �ȵɰ� ����
		return 0;
	}
	for (int i = n - 1; i >= 1; i--) {
		arr[len] = i;
		division(sum + i, len + i, dest);
	}
	// �̿ϼ� �ڵ� : ��? �ߺ����� ���͸��� ���⶧����
}

int main() {
	cin >> n;
	dest= n;
	division(0,0,dest);
*/