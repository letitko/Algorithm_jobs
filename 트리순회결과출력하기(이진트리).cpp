#include <iostream>
#define LEN 100
using namespace std;

class b_tree {
public:
	int left;
	int right;
};

b_tree tree[LEN + 1];

void preorder_circulation(int idx){ // ���� ��ȸ : ROOT->L->R

	if (tree[idx].left == -1 && tree[idx].right == -1) { // �ڽ� ��尡 ������ �ڱ� �ڽ� ���
		cout << idx << ' ';
	}
	else { // �ڽ� ��尡 ���� ���
		cout << idx << ' '; // ��Ʈ��� ���
		if (tree[idx].left != -1 ) { preorder_circulation(tree[idx].left); } // ���� �ڽ� ��尡 �ִٸ� ���� �ڽĳ�� �������� ������ȸ
		if (tree[idx].right != -1) { preorder_circulation(tree[idx].right); } // ���� �ڽ� ��尡 �ִٸ� ���� �ڽĳ�� �������� ������ȸ
	} // ���� ��ȸ : ROOT->L->R

}

void inorder_circulation(int idx) { // ���� ��ȸ : L->ROOT->R

	if (tree[idx].left == -1 && tree[idx].right == -1) { // �ڽ� ��尡 ������ �ڱ� �ڽ� ���
		cout << idx << ' ';
	}
	else { // �ڽ� ��尡 ���� ���

		if (tree[idx].left != -1) { inorder_circulation(tree[idx].left); } // ���� �ڽ� ��尡 �ִٸ� ���� �ڽĳ�� �������� ������ȸ
		cout << idx << ' '; // ��Ʈ��� ���
		if (tree[idx].right != -1) { inorder_circulation(tree[idx].right); } // ���� �ڽ� ��尡 �ִٸ� ���� �ڽĳ�� �������� ������ȸ

	} // ���� ��ȸ : L->ROOT->R

}

void postorder_circulation(int idx) { // ���� ��ȸ : L->R->ROOT

	if (tree[idx].left == -1 && tree[idx].right == -1) { // �ڽ� ��尡 ������ �ڱ� �ڽ� ���
		cout << idx << ' ';
	}
	else { // �ڽ� ��尡 ���� ���

		if (tree[idx].left != -1) { postorder_circulation(tree[idx].left); } // ���� �ڽ� ��尡 �ִٸ� ���� �ڽĳ�� �������� ������ȸ
		if (tree[idx].right != -1) { postorder_circulation(tree[idx].right); }  // ���� �ڽ� ��尡 �ִٸ� ���� �ڽĳ�� �������� ������ȸ
		cout << idx << ' '; // ��Ʈ��Ʈ ���
	}  // ���� ��ȸ : L->R->ROOT

}

int main() {

	int total; // ��ü ����� ����
	cin >> total;

	for (int s = 0; s < total; s++) { // �� �ݺ� Ƚ��
		int idx; // ��Ʈ ����� idx
		cin >> idx;
		cin >> tree[idx].left; // ��Ʈ ����� ���� �ڽ� ��� idx
		cin >> tree[idx].right; // ��Ʈ ����� ������ �ڽ� ��� idx
	}

	preorder_circulation(0); // ���� ��ȸ ROOT->L-R
	cout << endl;
	inorder_circulation(0); // ���� ��ȸ L->ROOT->R
	cout << endl;
	postorder_circulation(0); // ���� ��ȸ L->R->ROOT
	cout << endl;

}