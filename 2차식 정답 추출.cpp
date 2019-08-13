#include <iostream>
#define LEN 1000000000
using namespace std;

long long int binarysearch(long long int start, long long int end, long long int question) {

	if (start > end) {
		return -1;
	}
	else if (start == end) {
		if ((start * (start +1)) <= question && question < ((start+1) * ((start+1)+1)))  {
			return start;
		}
		else { return -1; }
	}

	long long int mid = (start + end) / 2;
	if ( (mid * (mid+1)) <= question && question < ( (mid + 1) * ((mid+1) + 1)) ) { return mid; }
	else if (mid * (mid + 1) > question) { return binarysearch(start, mid-1,question); }
	else { return binarysearch(mid +1, end,question); }
}


int main() {

	long long int question;
	cin >> question;

	long long int result = binarysearch(0, LEN, question);
	cout << result;
}