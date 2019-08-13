#include <iostream>
using namespace std;

int main() {

	int *ptr = (int *)malloc(sizeof(int) * 10);

	//심지어 위의 코드는 아래의 배열 선언과 완전히 동일하다.
	/*
		int ptr[10];
	*/


	*ptr = 10;
	*(ptr + 1) = 20;
	*(ptr + 2) = 30;

	for (int s = 0; s < 10; s++) {
		if (*(ptr + s) == NULL) { continue; }
		cout << *(ptr + s) << " ";
	}
	
	cout << endl;

	// 그런데 여기서 놀라운 사실은
	// 상위 포인터와 malloc 주소코드는
	// 결국 배열을 구현하기위한 변수와 함수의 관계임을
	// 알수 있다.

	for (int s = 0; s < 10; s++) {
		if (ptr[s] == NULL) { continue; }
		cout << ptr[s] << " ";
	}
}