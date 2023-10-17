//����� ��� ������ ������ �� ���������, �������������� � �����������������
//���������.��� ������� �������� ���������� : ���, ������, ������������
//�������������, ������� ����, ������� ����.��� ������� �������������
//���������� : ���; ����������� ������, ������� �����; ��������, �������
//���������.��� ����������������� ��������� ���������� : ���, ���������,
//�������, ������� ���������������.

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

		cout << "������� ��� ��������: ";
		cin.getline(name, 100);
		cout << "������� ������ ��������: ";
		cin.getline(group, 100);
		cout << "������� ������������� ��������: ";
		cin.getline(specialty, 100);
		cout << "������� ���� ��������: ";
		cin >> course;
		if (course <= 0) {
			throw UniversityException("������: ���� ������ ���� ������������� ������!");
		}
		cin.ignore(); // ������������� ������� ����� ������ �� ������� ������
		cout << "������� ������� ���� ��������: ";
		cin >> averageGrade;
		if (averageGrade < 0 || averageGrade > 5) {
			throw UniversityException("������: ������� ���� ������ ���� �� 0 �� 5!");
		}
		cin.ignore(); // ������������� ������� ����� ������ �� ������� ������

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
		cout << "������� ������ ��������, �������� ������ �������: ";
		cin >> index;
		if (index < 0 || index >= studentCount) {
			throw UniversityException("������: ������������ ������ ��������!");
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
			cout << "�������: " << name << endl;
			cout << "������: " << group << endl;
			cout << "�������������: " << specialty << endl;
			cout << "����: " << course << endl;
			cout << "������� ����: " << averageGrade << endl;
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
			throw UniversityException("������: �� ������� ������� ����!");
		}

		file << "----- University -----\n";

		for (int i = 0; i < university.studentCount; i++) {
			const University::Student* student = university.students[i];
			file << "�������: " << student->getName() << endl;
			file << "������: " << student->getGroup() << endl;
			file << "�������������: " << student->getSpecialty() << endl;
			file << "����: " << student->getCourse() << endl;
			file << "������� ����: " << student->getAverageGrade() << endl;
			file << "----------------------\n";
		}
		file.close();
	}

	void removeUniversityData() {
		ofstream file("university.txt");
		if (!file.is_open()) {
			throw UniversityException("������: �� ������� ������� ����!");
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