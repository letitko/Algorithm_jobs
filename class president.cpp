#include <iostream>
using namespace std;
#define CLASS 5
#define STUDENT 1000

// ���� : ����� �ߺ����� �־����İ��ƴ϶�, �� ���� �л���� �������̾������̴�.

class elementary {
public:
	int room[CLASS + 1] = { 0, };
	int score = 0;
};

int who_is_president(elementary student[STUDENT + 1],int total_student) {

	// �ߺ�Ƚ�� ���� Ž��
	for (int s = 1; s <= total_student; s++) {
		for (int k = 1; k <= total_student; k++) {
			for (int t = 1; t <= CLASS; t++) {
				if (student[s].room[t] == student[k].room[t]) {
					student[s].score++;
					break;
					//cout << s << "�� �л� ���� �� : " << student[s].score << endl;
			}
			}
		}
	}

	// �ְ��� �ߺ��� �ĺ� Ž��
	int biggest = -5;
	int index = 0;
	for (int t = 1; t <= total_student; t++) {
		if (student[t].score >= biggest) {
			biggest = student[t].score;
			index = t;
		}
	}

	// ���� ���� ������ �ĺ� Ž�� : ������ �� ��� ���
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

	// ������ �Է�
	for (int s = 1; s <= total_student; s++) {
		for(int t=1; t<=CLASS; t++){
		cin >> student[s].room[t];
		}
	}

	/*
	// ������ Ȯ��
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