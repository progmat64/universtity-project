#include "Library.h"
#include "Student.h"

using namespace std;

Student::Student() {}
Student::~Student() {}

Student::Student(const Student& Student_copy)
{
    name = Student_copy.name;
    group = Student_copy.group;
    specialty = Student_copy.specialty;
    course = Student_copy.course;
    averageGrade = Student_copy.averageGrade;
}

Student::Student(string name)
{
    this->name = name;
}

string Student::get_name() const { return name; }
void Student::set_name(string name_ch) { name = name_ch; }

string Student::get_group() const { return group; }
void Student::set_group(string group_ch) { group = group_ch; }

string Student::get_specialty() const { return specialty; }
void Student::set_specialty(string specialty_ch) { specialty = specialty_ch; }

string Student::get_course() const { return course; }
void Student::set_course(string course_ch) { course = course_ch; }

string Student::get_averageGrade() const { return averageGrade; }
void Student::set_averageGrade(string averageGrade_ch) { averageGrade = averageGrade_ch; }

void Student::show()
{
    setlocale(LC_ALL, "Russian");
    cout << "--------------------------------" << endl;
    cout << "Студент: " << name << endl;
    cout << "Группа: " << group << endl;
    cout << "Специальность: " << specialty << endl;
    cout << "Курс: " << course << endl;
    cout << "Средний балл: " << averageGrade << endl;
    cout << "--------------------------------" << endl;
}

void Student::rewrite()
{
    setlocale(LC_ALL, "Russian");
    cout << "--------------------------------" << endl;
    cin.ignore(32767, '\n');
    cout << "Введите нового студента: ";
    getline(cin, name);

    cout << "Введите новую группу: ";
    getline(cin, group);

    cout << "Введите новую специальность: ";
    getline(cin, specialty);

    cout << "Введите новый курс: ";
    getline(cin, course);

    cout << "Введите новый средний балл: ";
    getline(cin, averageGrade);


    cout << "--------------------------------" << endl;
}

void Student::saving()
{
    setlocale(LC_ALL, "Russian");
    ofstream outfile;
    string initfile = "university.txt";
    outfile.open(initfile, ios_base::app);
    if (!outfile)
    {
        throw "Ошибка!";
        system("pause");
        exit(1);
    }
    outfile << 1 << endl << name << endl << group << endl << specialty << endl << course << endl << averageGrade << endl;
    outfile.close();

}

void Student::redact_str(int num_str, string red_str)
{
    setlocale(LC_ALL, "Russian");
    switch (num_str)
    {
    case 1:
        this->name = red_str;
        break;
    case 2:

        break;
    case 3:
        this->specialty = red_str;

        break;
    case 4:
        this->course = red_str;

        break;
    case 5:
        this->averageGrade = red_str;

        break;
    default:
        throw "Ошибка пункта меню!";
        break;
    }
}
