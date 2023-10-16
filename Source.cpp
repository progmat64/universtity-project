
//����� ��� ������ ������ �� ���������, �������������� � �����������������
//���������.��� ������� �������� ���������� : ���, ������, ������������
//�������������, ������� ����, ������� ����.��� ������� �������������
//���������� : ���; ����������� ������, ������� �����; ��������, �������
//���������.��� ����������������� ��������� ���������� : ���, ���������,
//�������, ������� ���������������.


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
		// ����������� Student
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

		// ����� Student
		void print() {
			cout << "�������: " << name << endl;
			cout << "������: " << group << endl;
			cout << "�������������: " << specialty << endl;
			cout << "����: " << course << endl;
			cout << "������� ����: " << averageGrade << endl << endl;
		}
	};

};

int main() {
	setlocale(LC_ALL, "Russian");
	University suai;
	suai.addStudent("������ ���� ��������", "������ 1", "������������� 1", 3, 4.3);
}