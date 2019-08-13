#include <iostream>
#include <algorithm>
#define LEN 1000000
#define MAX_TREE 1000000000
using namespace std;

long long int trees[LEN];
int total_trees;
int need_tree_len;

int get_left(long long int * trees, int start, int end, long long int pivot, long long int * left);
int get_right(long long int * trees, int start, int end, long long int pivot, long long int * right);
void q_sort(long long int * trees, int start, int end);

long long int is_possible(long long int height) {
	long long int sum = 0;
	for (int idx = total_trees - 1; idx >= 0; idx--) {
		if (trees[idx] - height <= 0) {
			break;
		}
		if (trees[idx] - height > 0) {
			sum += (trees[idx] - height);
		}
	}
	return sum;
}

long long int nice_value = -789789789;

void find_height(long long int s, long long int e) {

	if (s >= e) {
		if (nice_value < s && is_possible(s) >= need_tree_len) { nice_value = s; }
		return;
	}

	long long int mid = (s + e) / 2;

	if (is_possible(mid) < need_tree_len) {
		return find_height(s, mid - 1);
	}
	else { //if (is_possible(mid) >= need_tree_len) 
		if (nice_value < mid && is_possible(mid) >= need_tree_len) { nice_value = mid; }
		return find_height(mid+1, e);
	}
}

int main() {

	cin >> total_trees;
	cin >> need_tree_len;

	for (int s = 0; s < total_trees; s++) {
		cin >> trees[s];
	}

	q_sort(trees, 0, total_trees - 1);
	//sort(trees, trees + total_trees);

	/*for (int s = 0; s < total_trees; s++) {
		cout << trees[s] << ' ';
	} cout << endl;*/

	find_height(0, MAX_TREE);
	cout << nice_value << endl;

}

int get_left(long long int * trees, int start, int end, long long int pivot, long long int * left) {

	int idx = 0;
	for (int s = start; s <= end; s++) {
		if (trees[s] <= pivot) {
			left[idx] = trees[s];
			idx++;
		}
	}

	return idx;
}
int get_right(long long int * trees, int start, int end, long long int pivot, long long int * right) {

	int idx = 0;
	for (int s = start; s <= end; s++) {
		if (trees[s] > pivot) {
			right[idx] = trees[s];
			idx++;
		}
	}

	return idx;
}
void q_sort(long long int * trees, int start, int end) {

	if (start >= end) { return; }

	long long int pivot = trees[start];

	static long long int left[LEN];
	static long long int right[LEN];

	int left_cnt = get_left(trees, start + 1, end, pivot, left);
	int right_cnt = get_right(trees, start + 1, end, pivot, right);

	// 합성부
	for (int s = 0; s < left_cnt; s++) {
		trees[start + s] = left[s];
	}
	trees[start + left_cnt] = pivot;

	for (int s = 0; s < right_cnt; s++) {
		trees[start + left_cnt + 1 + s] = right[s];
	}

	// 재귀부
	q_sort(trees, start, start + left_cnt - 1);
	q_sort(trees, start + left_cnt + 1, end);

}