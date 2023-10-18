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
			cout << "Студент: " << name << endl;
			cout << "Группа: " << group << endl;
			cout << "Специальность: " << specialty << endl;
			cout << "Курс: " << course << endl;
			cout << "Средний балл: " << averageGrade << endl;
		}

		void setName(const char* name) {
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}

		void setGroup(const char* group) {
			delete[] this->group;
			this->group = new char[strlen(group) + 1];
			strcpy(this->group, group);
		}

		void setSpecialty(const char* specialty) {
			delete[] this->specialty;
			this->specialty = new char[strlen(specialty) + 1];
			strcpy(this->specialty, specialty);
		}

		void setCourse(int course) {
			this->course = course;
		}

		void setAverageGrade(double averageGrade) {
			this->averageGrade = averageGrade;
		}

		const char* getName() const { return name; }
		const char* getGroup() const { return group; }
		const char* getSpecialty() const { return specialty; }
		int getCourse() const { return course; }
		double getAverageGrade() const { return averageGrade; }
	};

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

	void addStudent() {
		char name[100];
		char group[100];
		char specialty[100];
		int course;
		double averageGrade;

		cout << "Введите имя студента: ";
		cin.ignore();
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
			std::cout << "Преподаватель: " << name << std::endl;
			std::cout << "Группы: ";
			for (int i = 0; i < groupCount; i++) {
				std::cout << groups[i] << " ";
			}
			std::cout << std::endl;

			std::cout << "Предметы: ";
			for (int i = 0; i < subjectCount; i++) {
				std::cout << subjects[i] << " ";
			}
			std::cout << std::endl << std::endl;
		}

		void setName(const char* name) {
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}

		void setGroups(const char** groups, int groupCount) {
			for (int i = 0; i < groupCount; i++) {
				delete[] this->groups[i];
				this->groups[i] = new char[strlen(groups[i]) + 1];
				strcpy(this->groups[i], groups[i]);
			}
			this->groupCount = groupCount;
		}

		void setSubjects(const char** subjects, int subjectCount) {
			for (int i = 0; i < subjectCount; i++) {
				delete[] this->subjects[i];
				this->subjects[i] = new char[strlen(subjects[i]) + 1];
				strcpy(this->subjects[i], subjects[i]);
			}
			this->subjectCount = subjectCount;
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

	void addTeacher() {
		char* name = new char[100];
		cout << "Enter teacher's name: ";
		cin.ignore();
		cin.getline(name, 100);

		int groupCount;
		cout << "Enter the number of groups: ";
		cin >> groupCount;
		const char** groups = new const char* [groupCount];
		cout << "Enter the group names: ";
		for (int i = 0; i < groupCount; i++) {
			char* groupName = new char[100];
			cin >> groupName;
			groups[i] = groupName;
		}

		int subjectCount;
		cout << "Enter the number of subjects: ";
		cin >> subjectCount;
		const char** subjects = new const char* [subjectCount];
		cout << "Enter the subject names: ";
		for (int i = 0; i < subjectCount; i++) {
			char* subjectName = new char[100];
			cin >> subjectName;
			subjects[i] = subjectName;
		}

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
			throw UniversityException("Нет учителей для удаления.");
		}
		if (index < 0 || index >= teacherCount) {
			throw UniversityException("Неправильный индекс учителя.");
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

		void setName(const char* name) {
			delete[] this->name;
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}

		void setPosition(const char* position) {
			delete[] this->position;
			this->position = new char[strlen(position) + 1];
			strcpy(this->position, position);
		}

		void setPhone(const char* phone) {
			delete[] this->phone;
			this->phone = new char[strlen(phone) + 1];
			strcpy(this->phone, phone);
		}

		void setResponsibility(const char* responsibility) {
			delete[] this->responsibility;
			this->responsibility = new char[strlen(responsibility) + 1];
			strcpy(this->responsibility, responsibility);
		}

		void print() {
			std::cout << "Административный персонал: " << name << std::endl;
			std::cout << "Должность: " << position << std::endl;
			std::cout << "Телефон: " << phone << std::endl;
			std::cout << "Область ответственности: " << responsibility << std::endl << std::endl;
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

	void addStaff() {
		char name[100];
		char position[100];
		char phone[100];
		char responsibility[100];

		cout << "Enter name: ";
		cin.ignore();
		cin.getline(name, 100);

		cout << "Enter position: ";
		cin.getline(position, 100);

		cout << "Enter phone: ";
		cin.getline(phone, 100);

		cout << "Enter responsibility: ";
		cin.getline(responsibility, 100);

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
			throw UniversityException("Нет сотрудников для удаления.");
		}
		if (index < 0 || index >= staffCount) {
			throw UniversityException("Неправильный индекс сотрудника.");
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
			throw UniversityException("Ошибка: не удалось открыть файл!");
		}
		for (int i = 0; i < university.studentCount; i++) {
			const University::Student* student = university.students[i];
			file << "Студент: " << student->getName() << endl;
			file << "Группа: " << student->getGroup() << endl;
			file << "Специальность: " << student->getSpecialty() << endl;
			file << "Курс: " << student->getCourse() << endl;
			file << "Средний балл: " << student->getAverageGrade() << endl;
			file << "----------------------\n";
		}
		for (int i = 0; i < university.teacherCount; i++) {
			const University::Teacher* teacher = university.teachers[i];
			file << "Преподаватель: " << teacher->getName() << endl;
			file << "Группы: ";
			for (int j = 0; j < teacher->getGroupCount(); j++) {
				file << teacher->getGroups()[j] << " ";
			}
			file << endl;
			file << "Предметы: ";
			for (int j = 0; j < teacher->getSubjectCount(); j++) {
				file << teacher->getSubjects()[j] << " ";
			}
			file << endl;
			file << "----------------------\n";
		}
		for (int i = 0; i < university.staffCount; i++) {
			const University::Staff* staffMember = university.staff[i];
			file << "Административный персонал: " << staffMember->getName() << endl;
			file << "Должность: " << staffMember->getPosition() << endl;
			file << "Телефон: " << staffMember->getPhone() << endl;
			file << "Область ответственности: " << staffMember->getResponsibility() << endl;
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