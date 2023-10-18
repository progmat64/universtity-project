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
		teachers = nullptr;
		staff = nullptr;
		studentCount = 0;
		teacherCount = 0;
		staffCount = 0;
	}

	~University() {
		delete[] students;
		delete[] teachers;
		delete[] staff;
	}

	void printStudents() {
		for (int i = 0; i < studentCount; i++)
			students[i]->print();
	}

	void printTeachers() {
		for (int i = 0; i < teacherCount; i++) {
			teachers[i]->print();
		}
	}

	void printStaff() {
		for (int i = 0; i < staffCount; i++) {
			staff[i]->print();
		}
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////

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


///////////////////////////////////////////////////////////////////////////////////////////////////////

	class Teacher {
	public:
		Teacher(const char* name, const char** groups, int groupCount, const char** subjects, int subjectCount) {
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
			this->groups = new char* [groupCount];
			for (int i = 0; i < groupCount; i++) {
				this->groups[i] = new char[strlen(groups[i]) + 1];
				strcpy(this->groups[i], groups[i]);
			}
			this->groupCount = groupCount;
			this->subjects = new char* [subjectCount];
			for (int i = 0; i < subjectCount; i++) {
				this->subjects[i] = new char[strlen(subjects[i]) + 1];
				strcpy(this->subjects[i], subjects[i]);
			}
			this->subjectCount = subjectCount;
		}

		~Teacher() {
			delete[] name;

			for (int i = 0; i < groupCount; i++) {
				delete[] groups[i];
			}
			delete[] groups;

			for (int i = 0; i < subjectCount; i++) {
				delete[] subjects[i];
			}
			delete[] subjects;
		}

		void print() {
			std::cout << "�������������: " << name << std::endl;
			std::cout << "������: ";
			for (int i = 0; i < groupCount; i++) {
				std::cout << groups[i] << " ";
			}
			std::cout << std::endl;

			std::cout << "��������: ";
			for (int i = 0; i < subjectCount; i++) {
				std::cout << subjects[i] << " ";
			}
			std::cout << std::endl << std::endl;
		}

		const char* getName() const { return name; }
		char** getGroups() const { return groups; }
		int getGroupCount() const { return groupCount; }
		char** getSubjects() const { return subjects; }
		int getSubjectCount() const { return subjectCount; }

	private:
		char* name;
		char** groups;
		int groupCount;
		char** subjects;
		int subjectCount;
	};

	void addTeacher(const char* name, const char** groups, int groupCount, const char** subjects, int subjectCount) {
		Teacher* teacher = new Teacher(name, groups, groupCount, subjects, subjectCount);

		Teacher** newTeachers = new Teacher * [teacherCount + 1];
		for (int i = 0; i < teacherCount; i++) {
			newTeachers[i] = teachers[i];
		}
		newTeachers[teacherCount] = teacher;

		delete[] teachers;
		teachers = newTeachers;
		teacherCount++;
	}

	void removeTeacher(int index) {
		if (teacherCount == 0) {
			throw UniversityException("��� �������� ��� ��������.");
		}

		if (index < 0 || index >= teacherCount) {
			throw UniversityException("������������ ������ �������.");
		}

		Teacher* teacher = teachers[index];

		Teacher** newTeachers = new Teacher * [teacherCount - 1];
		int j = 0;
		for (int i = 0; i < teacherCount; i++) {
			if (i != index) {
				newTeachers[j] = teachers[i];
				j++;
			}
		}
		delete teacher;

		delete[] teachers;
		teachers = newTeachers;
		teacherCount--;
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////

	class Staff {
	public:
		Staff(const char* name, const char* position, const char* phone, const char* responsibility) {
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);

			this->position = new char[strlen(position) + 1];
			strcpy(this->position, position);

			this->phone = new char[strlen(phone) + 1];
			strcpy(this->phone, phone);

			this->responsibility = new char[strlen(responsibility) + 1];
			strcpy(this->responsibility, responsibility);
		}

		~Staff() {
			delete[] name;
			delete[] position;
			delete[] phone;
			delete[] responsibility;
		}

		void print() {
			std::cout << "���������������� ��������: " << name << std::endl;
			std::cout << "���������: " << position << std::endl;
			std::cout << "�������: " << phone << std::endl;
			std::cout << "������� ���������������: " << responsibility << std::endl << std::endl;
		}

		const char* getName() const { return name; }
		const char* getPosition() const { return position; }
		const char* getPhone() const { return phone; }
		const char* getResponsibility() const { return responsibility; }


	private:
		char* name;
		char* position;
		char* phone;
		char* responsibility;
	};

	void addStaff(const char* name, const char* position, const char* phone, const char* responsibility) {
		Staff* staffMember = new Staff(name, position, phone, responsibility);

		Staff** newStaff = new Staff * [staffCount + 1];
		for (int i = 0; i < staffCount; i++) {
			newStaff[i] = staff[i];
		}
		newStaff[staffCount] = staffMember;

		delete[] staff;
		staff = newStaff;
		staffCount++;
	}

	void removeStaff(int index) {
		if (staffCount == 0) {
			throw UniversityException("��� ����������� ��� ��������.");
		}

		if (index < 0 || index >= staffCount) {
			throw UniversityException("������������ ������ ����������.");
		}

		Staff* staffMember = staff[index];

		Staff** newStaff = new Staff * [staffCount - 1];
		int j = 0;
		for (int i = 0; i < staffCount; i++) {
			if (i != index) {
				newStaff[j] = staff[i];
				j++;
			}
		}

		delete staffMember;

		delete[] staff;
		staff = newStaff;
		staffCount--;
	}

	Student** students;
	int studentCount;

	Teacher** teachers;
	int teacherCount;

	Staff** staff;
	int staffCount;
};

class Keeper : University {
public:

	void saveUniversity(const University& university) {
		ofstream file("university.txt", ios::app);
		if (!file.is_open()) {
			throw UniversityException("������: �� ������� ������� ����!");
		}
		for (int i = 0; i < university.studentCount; i++) {
			const University::Student* student = university.students[i];
			file << "�������: " << student->getName() << endl;
			file << "������: " << student->getGroup() << endl;
			file << "�������������: " << student->getSpecialty() << endl;
			file << "����: " << student->getCourse() << endl;
			file << "������� ����: " << student->getAverageGrade() << endl;
			file << "----------------------\n";
		}
		for (int i = 0; i < university.teacherCount; i++) {
			const University::Teacher* teacher = university.teachers[i];
			file << "�������������: " << teacher->getName() << endl;
			file << "������: ";
			for (int j = 0; j < teacher->getGroupCount(); j++) {
				file << teacher->getGroups()[j] << " ";
			}
			file << endl;
			file << "��������: ";
			for (int j = 0; j < teacher->getSubjectCount(); j++) {
				file << teacher->getSubjects()[j] << " ";
			}
			file << endl;
			file << "----------------------\n";
		}
		for (int i = 0; i < university.staffCount; i++) {
			const University::Staff* staffMember = university.staff[i];
			file << "���������������� ��������: " << staffMember->getName() << endl;
			file << "���������: " << staffMember->getPosition() << endl;
			file << "�������: " << staffMember->getPhone() << endl;
			file << "������� ���������������: " << staffMember->getResponsibility() << endl;
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

	const char* teacherGroups[] = { "Group A", "Group B", "Group C" };
	const char* teacherSubjects[] = { "Subject 1", "Subject 2", "Subject 3" };

	try {
		suai.addTeacher("������", teacherGroups, 2, teacherSubjects, 2);
		suai.printTeachers();

		suai.printTeachers();

		suai.addStaff("������", "�������������", "+123456789", "���������� �������");

	}
	catch (UniversityException& ex) {
		cout << "������: " << ex.what() << endl;
	}

	Keeper keeper;
	keeper.saveUniversity(suai);
	keeper.removeUniversityData();
}