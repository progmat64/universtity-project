#include "Library.h"

using namespace std;

Staff::Staff() {}

Staff::~Staff() {}


Staff::Staff(const Staff& Staff_copy)
{
    name = Staff_copy.name;
    position = Staff_copy.position;
    phone = Staff_copy.phone;
    responsibility = Staff_copy.responsibility;
}

Staff::Staff(string name)
{
    this->name = name;
}

string Staff::get_name() const { return name; }
void Staff::set_name(string name_ch) { name = name_ch; }

string Staff::get_position() const { return position; }
void Staff::set_position(string position_ch) { position = position_ch; }

string Staff::get_phone() const { return phone; }
void Staff::set_phone(string phone_ch) { phone = phone_ch; }

string Staff::get_responsibility() const { return responsibility; }
void Staff::set_responsibility(string responsibility_ch) { responsibility = responsibility_ch; }

void Staff::show()
{
    setlocale(LC_ALL, "Russian");
    cout << "--------------------------------" << endl;
    cout << "Имя: " << name << endl;
    cout << "Должность: " << position << endl;
    cout << "Телефон: " << phone << endl;
    cout << "Обасть ответственности: " << responsibility << endl;
    cout << "--------------------------------" << endl;
}

void Staff::rewrite()
{
    setlocale(LC_ALL, "Russian");
    cout << "--------------------------------" << endl;
    cin.ignore(32767, '\n');
    cout << "Введите новое имя: ";
    getline(cin, name);
    cout << "Введите новую должность: ";
    getline(cin, position);
    cout << "Введите новый телефон: ";
    getline(cin, phone);
    cout << "Введите область ответственности: ";
    getline(cin, responsibility);
    cout << "--------------------------------" << endl;
}

void Staff::saving()
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
    outfile << 3 << endl << name << endl << position << endl << phone << endl << responsibility << endl;
    outfile.close();

}

void Staff::redact_str(int num_str, string red_str)
{
    setlocale(LC_ALL, "Russian");
    switch (num_str)
    {
    case 1:
        this->name = red_str;
        break;
    case 2:
        this->position = red_str;
        break;
    case 3:
        this->phone = red_str;
        break;
    case 4:
        this->responsibility = red_str;
        break;
    default:
        throw "Ошибка номера меню";
        break;
    }
}

