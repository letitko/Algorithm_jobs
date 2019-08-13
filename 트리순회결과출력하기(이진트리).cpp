#include <iostream>
#define LEN 100
using namespace std;

class b_tree {
public:
	int left;
	int right;
};

b_tree tree[LEN + 1];

void preorder_circulation(int idx){ // 전위 순회 : ROOT->L->R

	if (tree[idx].left == -1 && tree[idx].right == -1) { // 자식 노드가 없으면 자기 자신 출력
		cout << idx << ' ';
	}
	else { // 자식 노드가 있을 경우
		cout << idx << ' '; // 루트노드 출력
		if (tree[idx].left != -1 ) { preorder_circulation(tree[idx].left); } // 좌측 자식 노드가 있다면 좌측 자식노드 기준으로 전위순회
		if (tree[idx].right != -1) { preorder_circulation(tree[idx].right); } // 우측 자식 노드가 있다면 좌측 자식노드 기준으로 전위순회
	} // 전위 순회 : ROOT->L->R

}

void inorder_circulation(int idx) { // 중위 순회 : L->ROOT->R

	if (tree[idx].left == -1 && tree[idx].right == -1) { // 자식 노드가 없으면 자기 자신 출력
		cout << idx << ' ';
	}
	else { // 자식 노드가 있을 경우

		if (tree[idx].left != -1) { inorder_circulation(tree[idx].left); } // 좌측 자식 노드가 있다면 좌측 자식노드 기준으로 중위순회
		cout << idx << ' '; // 루트노드 출력
		if (tree[idx].right != -1) { inorder_circulation(tree[idx].right); } // 우측 자식 노드가 있다면 좌측 자식노드 기준으로 중위순회

	} // 중위 순회 : L->ROOT->R

}

void postorder_circulation(int idx) { // 후위 순회 : L->R->ROOT

	if (tree[idx].left == -1 && tree[idx].right == -1) { // 자식 노드가 없으면 자기 자신 출력
		cout << idx << ' ';
	}
	else { // 자식 노드가 있을 경우

		if (tree[idx].left != -1) { postorder_circulation(tree[idx].left); } // 좌측 자식 노드가 있다면 좌측 자식노드 기준으로 후위순회
		if (tree[idx].right != -1) { postorder_circulation(tree[idx].right); }  // 우측 자식 노드가 있다면 좌측 자식노드 기준으로 후위순회
		cout << idx << ' '; // 루트노트 출력
	}  // 후위 순회 : L->R->ROOT

}

int main() {

	int total; // 전체 노드의 갯수
	cin >> total;

	for (int s = 0; s < total; s++) { // 총 반복 횟수
		int idx; // 루트 노드의 idx
		cin >> idx;
		cin >> tree[idx].left; // 루트 노드의 왼쪽 자식 노드 idx
		cin >> tree[idx].right; // 루트 노드의 오른쪽 자식 노드 idx
	}

	preorder_circulation(0); // 전위 순회 ROOT->L-R
	cout << endl;
	inorder_circulation(0); // 중위 순회 L->ROOT->R
	cout << endl;
	postorder_circulation(0); // 후위 순회 L->R->ROOT
	cout << endl;

}