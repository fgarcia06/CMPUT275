#include <iostream>

using namespace std;

struct Student {
	char name[40];
	int grade;
};

void display_struct(Student a_student) {
	cout << "Name: " << a_student.name << endl
 		 << "Grade: " << a_student.grade << endl
 		 << endl;
}

int main() {
	Student zac = {"Zac Friggstad", 92};

	display_struct(zac);

	Student& identity_thief = zac;

	identity_thief.name[2] = 'k';

	display_struct(zac);

	Student* zac_ptr = &zac;
	Student* thief_ptr = &identity_thief;

	if (zac_ptr == thief_ptr) {
		cout << "The pointers are the same" << endl << endl;
	}

	zac_ptr->grade = 78;

	display_struct(zac);

	return 0;
}
