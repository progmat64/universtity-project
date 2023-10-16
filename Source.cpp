
//Класс ВУЗ хранит данные по студентам, преподавателям и административному
//персоналу.Для каждого студента определено : ФИО, группа, наименование
//специальности, текущий курс, средний балл.Для каждого преподавателя
//определено : ФИО; перечислены группы, которые ведет; предметы, которые
//преподает.Для административного персонала определено : ФИО, должность,
//телефон, область ответственности.


using namespace std;
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
class University {
public:

	University() {
		char* students;
	}

	void addStudent(const char* name, const char* group, const char* specialty, int course, double averageGrade) {
		Student* newStudent = new Student(name, group, specialty, course, averageGrade);
		newStudent->print();
	}

	void printStudents() {}


private:
	class Student {
	private:
		char* name;
		char* group;
		char* specialty;
		int course;
		double averageGrade;
	public:
		// Конструктор Student
		Student(const char* name, const char* group, const char* specialty, int course, double averageGrade) {
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);

			this->group = new char[strlen(group) + 1];
			strcpy(this->group, group);

			this->specialty = new char[strlen(specialty) + 1];
			strcpy(this->specialty, specialty);

			this->course = course;
			this->averageGrade = averageGrade;
		}

		// Вывод Student
		void print() {
			cout << "Студент: " << name << endl;
			cout << "Группа: " << group << endl;
			cout << "Специальность: " << specialty << endl;
			cout << "Курс: " << course << endl;
			cout << "Средний балл: " << averageGrade << endl << endl;
		}
	};

};

int main() {
	setlocale(LC_ALL, "Russian");
	University suai;
	suai.addStudent("Иванов Иван Иванович", "Группа 1", "Специальность 1", 3, 4.3);
}