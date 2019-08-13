#include <iostream>
using namespace std;
#define CLASS 5
#define STUDENT 1000

// 주의 : 몇번의 중복반이 있었느냐가아니라, 몇 명의 학생들과 같은반이었느냐이다.

class elementary {
public:
	int room[CLASS + 1] = { 0, };
	int score = 0;
};

int who_is_president(elementary student[STUDENT + 1],int total_student) {

	// 중복횟수 각각 탐색
	for (int s = 1; s <= total_student; s++) {
		for (int k = 1; k <= total_student; k++) {
			for (int t = 1; t <= CLASS; t++) {
				if (student[s].room[t] == student[k].room[t]) {
					student[s].score++;
					break;
					//cout << s << "번 학생 실행 중 : " << student[s].score << endl;
			}
			}
		}
	}

	// 최고의 중복자 후보 탐색
	int biggest = -5;
	int index = 0;
	for (int t = 1; t <= total_student; t++) {
		if (student[t].score >= biggest) {
			biggest = student[t].score;
			index = t;
		}
	}

	// 최초 순번 종결자 후보 탐색 : 여러명 일 경우 고려
	for (int t = 1; t <= total_student; t++) {
		if (student[t].score == biggest) {
			index = t;
			break;
		}
	}

	return index;
}

int main() {
	elementary student[STUDENT + 1];
	int total_student;
	cin >> total_student;

	// 데이터 입력
	for (int s = 1; s <= total_student; s++) {
		for(int t=1; t<=CLASS; t++){
		cin >> student[s].room[t];
		}
	}

	/*
	// 데이터 확인
	for (int s = 1; s <= total_student; s++) {
		for (int t = 1; t <= CLASS; t++) {
			cout << student[s].room[t] << " ";
		}
		cout << endl;
	}
	*/

	int result;
	result = who_is_president(student, total_student);
	cout << result << endl;

}