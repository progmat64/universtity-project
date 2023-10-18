#define _CRT_SECURE_NO_WARNINGS
#include "University.h"

University::University() {
        students = nullptr;
        teachers = nullptr;
        staff = nullptr;
        studentCount = 0;
        teacherCount = 0;
        staffCount = 0;
}

University::~University() {
        delete[] students;
        delete[] teachers;
        delete[] staff;
}

void University::printStudents() {
        for (int i = 0; i < studentCount; i++)
                students[i]->print();
}

void University::printTeachers() {
        for (int i = 0; i < teacherCount; i++) {
                teachers[i]->print();
        }
}

void University::printStaff() {
        for (int i = 0; i < staffCount; i++) {
                staff[i]->print();
        }
}

University::Student::Student(const char* name, const char* group, const char* specialty, int course, double averageGrade) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

        this->group = new char[strlen(group) + 1];
        strcpy(this->group, group);

        this->specialty = new char[strlen(specialty) + 1];
        strcpy(this->specialty, specialty);

        this->course = course;
        this->averageGrade = averageGrade;
}

University::Student::~Student() {
        delete[] name;
        delete[] group;
        delete[] specialty;
}

void University::Student::print() {
        std::cout << "Студент: " << name << std::endl;
        std::cout << "Группа: " << group << std::endl;
        std::cout << "Специальность: " << specialty << std::endl;
        std::cout << "Курс: " << course << std::endl;
        std::cout << "Средний балл: " << averageGrade << std::endl;
}

void University::Student::setName(const char* name) {
        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
}

void University::Student::setGroup(const char* group) {
        delete[] this->group;
        this->group = new char[strlen(group) + 1];
        strcpy(this->group, group);
}

void University::Student::setSpecialty(const char* specialty) {
        delete[] this->specialty;
        this->specialty = new char[strlen(specialty) + 1];
        strcpy(this->specialty, specialty);
}

void University::Student::setCourse(int course) {
        this->course = course;
}

void University::Student::setAverageGrade(double averageGrade) {
        this->averageGrade = averageGrade;
}

const char* University::Student::getName() const { return name; }
const char* University::Student::getGroup() const { return group; }
const char* University::Student::getSpecialty() const { return specialty; }
int University::Student::getCourse() const { return course; }
double University::Student::getAverageGrade() const { return averageGrade; }

void University::removeStudent() {
    int index;
    std::cout << "Введите индекс студента, которого хотите удалить: ";
    std::cin >> index;
    if (index < 0 || index >= studentCount) {
            throw UniversityException("Ошибка: неправильный индекс студента!");
    }
    delete students[index];
    for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
    }
    studentCount--;
}

void University::addStudent() {
    char name[100];
    char group[100];
    char specialty[100];
    int course;
    double averageGrade;

    std::cout << "Введите имя студента: ";
    std::cin.ignore();
    std::cin.getline(name, 100);
    std::cout << "Введите группу студента: ";
    std::cin.getline(group, 100);
    std::cout << "Введите специальность студента: ";
    std::cin.getline(specialty, 100);
    std::cout << "Введите курс студента: ";
    std::cin >> course;
    if (course <= 0) {
            throw UniversityException("Ошибка: курс должен быть положительным числом!");
    }
    std::cin.ignore(); // Игнорирование символа новой строки во входном буфере
    std::cout << "Введите средний балл студента: ";
    std::cin >> averageGrade;
    if (averageGrade < 0 || averageGrade > 5) {
            throw UniversityException("Ошибка: средний балл должен быть от 0 до 5!");
    }
    std::cin.ignore(); // Игнорирование символа новой строки во входном буфере

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

void University::editStudent(University& university)
{
    int index;
    std::cout << "Enter the index of the student you want to edit: ";
    std::cin >> index;
    if (index < 0 || index >= university.studentCount) {
        throw UniversityException("Error: Invalid student index!");
    }

    Student* student = university.students[index];

    char name[100];
    char group[100];
    char specialty[100];
    int course;
    double averageGrade;

    std::cout << "Enter new name: ";
    std::cin.ignore();
    std::cin.getline(name, 100);
    std::cout << "Enter new group: ";
    std::cin.getline(group, 100);
    std::cout << "Enter new specialty: ";
    std::cin.getline(specialty, 100);
    std::cout << "Enter new course: ";
    std::cin >> course;
    std::cout << "Enter new average grade: ";
    std::cin >> averageGrade;

    student->setName(name);
    student->setGroup(group);
    student->setSpecialty(specialty);
    student->setCourse(course);
    student->setAverageGrade(averageGrade);
}

University::Teacher::Teacher(const char* name, const char** groups, int groupCount, const char** subjects, int subjectCount) {
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

University::Teacher::~Teacher() {
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

void University::Teacher::print() {
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

void University::Teacher::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void University::Teacher::setGroups(const char** groups, int groupCount) {
    for (int i = 0; i < groupCount; i++) {
            delete[] this->groups[i];
            this->groups[i] = new char[strlen(groups[i]) + 1];
            strcpy(this->groups[i], groups[i]);
    }
    this->groupCount = groupCount;
}

void University::Teacher::setSubjects(const char** subjects, int subjectCount) {
    for (int i = 0; i < subjectCount; i++) {
            delete[] this->subjects[i];
            this->subjects[i] = new char[strlen(subjects[i]) + 1];
            strcpy(this->subjects[i], subjects[i]);
    }
    this->subjectCount = subjectCount;
}

const char* University::Teacher::getName() const { return name; }
char** University::Teacher::getGroups() const { return groups; }
int University::Teacher::getGroupCount() const { return groupCount; }
char** University::Teacher::getSubjects() const { return subjects; }
int University::Teacher::getSubjectCount() const { return subjectCount; }

void University::addTeacher() {
    char* name = new char[100];
    std::cout << "Enter teacher's name: ";
    std::cin.ignore();
    std::cin.getline(name, 100);

    int groupCount;
    std::cout << "Enter the number of groups: ";
    std::cin >> groupCount;
    const char** groups = new const char* [groupCount];
    std::cout << "Enter the group names: ";
    for (int i = 0; i < groupCount; i++) {
            char* groupName = new char[100];
            std::cin >> groupName;
            groups[i] = groupName;
    }

    int subjectCount;
    std::cout << "Enter the number of subjects: ";
    std::cin >> subjectCount;
    const char** subjects = new const char* [subjectCount];
    std::cout << "Enter the subject names: ";
    for (int i = 0; i < subjectCount; i++) {
            char* subjectName = new char[100];
            std::cin >> subjectName;
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

void University::removeTeacher(int index) {
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

void University::editTeacher(University& university)
{
    int index;
    std::cout << "Enter the index of the teacher you want to edit: ";
    std::cin >> index;
    if (index < 0 || index >= university.teacherCount) {
        throw UniversityException("Error: Invalid teacher index!");
    }

    Teacher* teacher = university.teachers[index];

    char name[100];
    int groupCount;
    const char** groups;
    int subjectCount;
    const char** subjects;

    std::cout << "Enter new name: ";
    std::cin.ignore();
    std::cin.getline(name, 100);
    std::cout << "Enter the number of groups: ";
    std::cin >> groupCount;

    groups = new const char* [groupCount];
    std::cout << "Enter the group names: ";
    for (int i = 0; i < groupCount; i++) {
        char groupName[100];
        std::cin >> groupName;
        groups[i] = groupName;
    }

    std::cout << "Enter the number of subjects: ";
    std::cin >> subjectCount;

    subjects = new const char* [subjectCount];
    std::cout << "Enter the subject names: ";
    for (int i = 0; i < subjectCount; i++) {
        char subjectName[100];
        std::cin >> subjectName;
        subjects[i] = subjectName;
    }

    teacher->setName(name);
    teacher->setGroups(groups, groupCount);
    teacher->setSubjects(subjects, subjectCount);

    delete[] groups;
    delete[] subjects;
}

University::Staff::Staff(const char* name, const char* position, const char* phone, const char* responsibility) 
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->position = new char[strlen(position) + 1];
    strcpy(this->position, position);

    this->phone = new char[strlen(phone) + 1];
    strcpy(this->phone, phone);

    this->responsibility = new char[strlen(responsibility) + 1];
    strcpy(this->responsibility, responsibility);
}

University::Staff::~Staff() {
    delete[] name;
    delete[] position;
    delete[] phone;
    delete[] responsibility;
}

void University::Staff::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void University::Staff::setPosition(const char* position) {
    delete[] this->position;
    this->position = new char[strlen(position) + 1];
    strcpy(this->position, position);
}

void University::Staff::setPhone(const char* phone) {
    delete[] this->phone;
    this->phone = new char[strlen(phone) + 1];
    strcpy(this->phone, phone);
}

void University::Staff::setResponsibility(const char* responsibility) {
    delete[] this->responsibility;
    this->responsibility = new char[strlen(responsibility) + 1];
    strcpy(this->responsibility, responsibility);
}

void University::Staff::print() {
    std::cout << "Административный персонал: " << name << std::endl;
    std::cout << "Должность: " << position << std::endl;
    std::cout << "Телефон: " << phone << std::endl;
    std::cout << "Область ответственности: " << responsibility << std::endl << std::endl;
}

const char* University::Staff::getName() const { return name; }
const char* University::Staff::getPosition() const { return position; }
const char* University::Staff::getPhone() const { return phone; }
const char* University::Staff::getResponsibility() const { return responsibility; }

void University::addStaff() {
    char name[100];
    char position[100];
    char phone[100];
    char responsibility[100];

    std::cout << "Enter name: ";
    std::cin.ignore();
    std::cin.getline(name, 100);

    std::cout << "Enter position: ";
    std::cin.getline(position, 100);

    std::cout << "Enter phone: ";
    std::cin.getline(phone, 100);

    std::cout << "Enter responsibility: ";
    std::cin.getline(responsibility, 100);

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

void University::removeStaff(int index) {
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

void University::editStaff(University& university)
{
    int index;
    std::cout << "Enter the index of the staff member you want to edit: ";
    std::cin >> index;
    if (index < 0 || index >= university.staffCount) {
        throw UniversityException("Error: Invalid staff member index!");
    }

    Staff* staffMember = university.staff[index];

    char name[100];
    char position[100];
    char phone[100];
    char responsibility[100];

    std::cout << "Enter new name: ";
    std::cin.ignore();
    std::cin.getline(name, 100);
    std::cout << "Enter new position: ";
    std::cin.getline(position, 100);
    std::cout << "Enter new phone: ";
    std::cin.getline(phone, 100);
    std::cout << "Enter new responsibility: ";
    std::cin.getline(responsibility, 100);

    staffMember->setName(name);
    staffMember->setPosition(position);
    staffMember->setPhone(phone);
    staffMember->setResponsibility(responsibility);
}
