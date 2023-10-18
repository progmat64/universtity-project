#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
#include "University.h"
#include "Keeper.h"

using namespace std;

void Menu(University vuz) {
	Keeper keeper;
	int choose = 1;
	cout << "1) Добавить студента" << endl;
	cout << "2) Удалить студента" << endl;

	cout << "3) Добавить преподавателя" << endl;
	cout << "4) Удалить преподавателя" << endl;

	cout << "5) Добавить персонал" << endl;
	cout << "6) Удалить персонал" << endl;

	cout << "7) Сохранить данные в файл" << endl;
	cout << "8) Удалить данные из файла" << endl;

	cout << "9) Изменить данные студента" << endl;
	cout << "10) Изменить данные преподавателя" << endl;
	cout << "11) Изменить данные персонала" << endl;

	cout << "0) Выйти" << endl;

	int index = 0;

	while (choose != 0)
	{
		cout << "Team number ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			vuz.addStudent();
			vuz.printStudents();
			break;
		case 2:
			vuz.removeStudent();
			vuz.printStudents();
			break;
		case 3:
			vuz.addTeacher();
			vuz.printTeachers();
			break;
		case 4:
			cout << "index = ";
			cin >> index;
			vuz.removeTeacher(index);
			vuz.printTeachers();
			break;
		case 5:
			vuz.addStaff();
			vuz.printStaff();
			break;
		case 6:
			cout << "index = ";
			cin >> index;
			vuz.removeStaff(index);
			vuz.printStaff();
			break;
		case 7:
			keeper.saveUniversity(vuz);
			break;
		case 8:
			keeper.removeUniversityData();
			break;
		case 9:
			vuz.editStudent(vuz);
			vuz.printStudents();
			break;
		case 10:
			vuz.editTeacher(vuz);
			vuz.printTeachers();
			break;
		case 11:
			vuz.editStaff(vuz);
			vuz.printStaff();
			break;
		case 0:
			exit(0);
		default:
			cout << "Неправильный выбор" << endl;
			break;
		}
	}
}

int main() {
	system("chcp 1251");
	University suai;
	Menu(suai);
}
