//Класс ВУЗ хранит данные по студентам, преподавателям и административному
//персоналу.Для каждого студента определено : ФИО, группа, наименование
//специальности, текущий курс, средний балл.Для каждого преподавателя
//определено : ФИО; перечислены группы, которые ведет; предметы, которые
//преподает.Для административного персонала определено : ФИО, должность,
//телефон, область ответственности.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class UniversityException : public exception {
public:
	UniversityException(const char* message) : exception(message) {}
};

class University {
public:
	University() {
		students = nullptr;
		studentCount = 0;
	}

	~University() {
		delete[] students;
	}

	void addStudent() {
		char name[100];
		char group[100];
		char specialty[100];
		int course;
		double averageGrade;

		cout << "Введите имя студента: ";
		cin.getline(name, 100);
		cout << "Введите группу студента: ";
		cin.getline(group, 100);
		cout << "Введите специальность студента: ";
		cin.getline(specialty, 100);
		cout << "Введите курс студента: ";
		cin >> course;
		if (course <= 0) {
			throw UniversityException("Ошибка: курс должен быть положительным числом!");
		}
		cin.ignore(); // Игнорирование символа новой строки во входном буфере
		cout << "Введите средний балл студента: ";
		cin >> averageGrade;
		if (averageGrade < 0 || averageGrade > 5) {
			throw UniversityException("Ошибка: средний балл должен быть от 0 до 5!");
		}
		cin.ignore(); // Игнорирование символа новой строки во входном буфере

		Student* newStudent = new Student(name, group, specialty, course, averageGrade);
		Student** newStudents = new Student * [studentCount + 1];
		for (int i = 0; i < studentCount; i++) {
			newStudents[i] = students[i];
		}
		newStudents[studentCount] = newStudent;
		delete[] students;
		students = newStudents;
		studentCount++;
	}

	void removeStudent() {
		int index;
		cout << "Введите индекс студента, которого хотите удалить: ";
		cin >> index;
		if (index < 0 || index >= studentCount) {
			throw UniversityException("Ошибка: неправильный индекс студента!");
		}
		delete students[index];
		for (int i = index; i < studentCount - 1; i++) {
			students[i] = students[i + 1];
		}
		studentCount--;
	}

	void printStudents() {
		for (int i = 0; i < studentCount; i++)
			students[i]->print();
	}

	class Student {
	private:
		char* name;
		char* group;
		char* specialty;
		int course;
		double averageGrade;


	public:
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

		~Student() {
			delete[] name;
			delete[] group;
			delete[] specialty;
		}

		void print() {
			cout << "Студент: " << name << endl;
			cout << "Группа: " << group << endl;
			cout << "Специальность: " << specialty << endl;
			cout << "Курс: " << course << endl;
			cout << "Средний балл: " << averageGrade << endl;
		}

		const char* getName() const { return name; }
		const char* getGroup() const { return group; }
		const char* getSpecialty() const { return specialty; }
		int getCourse() const { return course; }
		double getAverageGrade() const { return averageGrade; }
	};

	Student** students;
	int studentCount;


};

class Keeper : University {
public:
	void saveUniversity(const University& university) {
		ofstream file("university.txt", ios::app);
		if (!file.is_open()) {
			throw UniversityException("Ошибка: не удалось открыть файл!");
		}

		file << "----- University -----\n";

		for (int i = 0; i < university.studentCount; i++) {
			const University::Student* student = university.students[i];
			file << "Студент: " << student->getName() << endl;
			file << "Группа: " << student->getGroup() << endl;
			file << "Специальность: " << student->getSpecialty() << endl;
			file << "Курс: " << student->getCourse() << endl;
			file << "Средний балл: " << student->getAverageGrade() << endl;
			file << "----------------------\n";
		}
		file.close();
	}

	void removeUniversityData() {
		ofstream file("university.txt");
		if (!file.is_open()) {
			throw UniversityException("Ошибка: не удалось открыть файл!");
		}
		file.close();
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	University suai;
	suai.addStudent();
	suai.addStudent();

	Keeper keeper;
	keeper.saveUniversity(suai);
	keeper.removeUniversityData();
}