#include "Library.h"

using namespace std;

Teacher::Teacher() {}

Teacher::~Teacher() {}

Teacher::Teacher(const Teacher& Textbook_copy)
{
	name = Textbook_copy.name;
	groups = Textbook_copy.groups;
	subjects = Textbook_copy.subjects;

}

Teacher::Teacher(string name)
{
	this->name = name;
}

string Teacher::get_name() const { return name; }
void Teacher::set_name(string name_ch) { name = name_ch; }

string Teacher::get_groups() const { return groups; }
void Teacher::set_groups(string groups_ch) { groups = groups_ch; }

string Teacher::get_subjects() const { return subjects; }
void Teacher::set_subjects(string subjects_ch) { subjects = subjects_ch; }

void Teacher::show()
{
	setlocale(LC_ALL, "Russian");
	cout << "--------------------------------" << endl;
	cout << "Имя: " << name << endl;
	cout << "Группы: " << groups << endl;
	cout << "Предметы: " << subjects << endl;
	cout << "--------------------------------" << endl;
}

void Teacher::rewrite()
{
	setlocale(LC_ALL, "Russian");
	cout << "--------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Введите нового преподавателя: ";
	getline(cin, name);
	cout << "Введите новые группы: ";
	getline(cin, groups);
	cout << "Введите новые предметы: ";
	getline(cin, subjects);
	cout << "--------------------------------" << endl;
}

void Teacher::saving()
{
	setlocale(LC_ALL, "Russian");
	ofstream outfile;
	string initfile = "university.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile)
	{
		throw "Ошибка файла";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << 2 << endl << name << endl << groups << endl << subjects << endl;
		outfile.close();
	}

}

void Teacher::redact_str(int num_str, string red_str)
{
	setlocale(LC_ALL, "Russian");
	switch (num_str)
	{
	case 1:
		this->name = red_str;
		break;
	case 2:
		this->groups = red_str;
		break;
	case 3:
		this->subjects = red_str;
		break;
	default:
		throw "Неверный номер меню";
		break;
	}
}
