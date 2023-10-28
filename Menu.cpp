#include "Library.h"

using namespace std;

void Menu::main_menu()
{
    while (exit == 1)
    {
        switch (show_options())
        {
        case 1:
            show_all_Universitys();
            break;
        case 2:
            change_data();
            break;
        case 3:
            add_new();
            break;
        case 4:
            save_to_file();
            break;
        case 5:
            load_from_file();
            break;
        case 6:
            delete_University();
            break;
        default:
            exit_from_programm();
            break;
        }
    }
}



int Menu::show_options()
{
    int c1;
    setlocale(LC_ALL, "Russian");
    cout << "\nВыбиерете пункт меню" << endl;
    cout << "1 - Показать все" << endl;
    cout << "2 - Изменить данные" << endl;
    cout << "3 - Добавить новые данные" << endl;
    cout << "4 - Сохранить всю информацию в файл" << endl;
    cout << "5 - Загрузить информацию из файла" << endl;
    cout << "6 - Удалить" << endl;
    cout << "0 - Exit" << endl;
    cout << "->  ";
    cin >> c1;
    return c1;
}

void Menu::show_all_Universitys()
{
    system("cls");
    try
    {
        if (list.get_size() == 0)
        {
            throw "Пусто";
        }
        for (int i = 0; i < list.get_size(); i++)
        {
            cout << "[" << i + 1 << "]";
            list[i]->show();
        }
    }
    catch (const char* ex) { cout << ex << endl; }
    system("pause");
}

void Menu::change_data()
{
    int c2, c3;
    system("cls");
    try
    {
        cout << "Что изменить? " << list.get_size() << endl;
        cin >> c2;

        if ((c2 < 1) || (c2 > list.get_size()))
        {
            throw "Ошибка!";
        }

        list[c2 - 1]->show();
        cout << "Какую строку поменять?" << endl;
        cout << "->  ";
        cin >> c3;
        cin.ignore(32767, '\n');
        cout << "Что записать?" << endl;
        cout << "->  ";
        if (c3 == 5)
        {
            bool fl = false;
            while (fl == false)
            {
                try
                {

                    getline(cin, redact);
                    float f = stof(redact);
                    fl = true;
                }
                catch (...)
                {
                    cout << "Введите число" << endl;

                }
            }
            list[c2 - 1]->redact_str(c3, redact);
        }
        else
        {
            getline(cin, redact);
            list[c2 - 1]->redact_str(c3, redact);
            cout << "Изменено" << endl;
        }
    }
    catch (const char* ex) { cout << ex << endl; }
    system("pause");
}

void Menu::add_new()
{
    int c2;
    system("cls");
    cout << "\nЧто добавить?" << endl;
    cout << "1 - Студента" << endl;
    cout << "2 - Преподавателя" << endl;
    cout << "3 - Персонал" << endl;
    cout << "0 - Назад" << endl;
    cout << "->  ";
    cin >> c2;

    switch (c2)
    {
    case 1:
        Student * book;
        book = new Student;
        Universitys = book;
        book->rewrite();
        list.insert(Universitys);
        cout << "Добавлен" << endl;
        break;
    case 2:
        Teacher * Textbook;
        Textbook = new Teacher;
        Universitys = Textbook;
        Textbook->rewrite();
        list.insert(Universitys);
        cout << "Добавлен" << endl;
        break;
    case 3:
        Staff * emp;
        emp = new Staff;
        Universitys = emp;
        emp->rewrite();
        list.insert(Universitys);
        cout << "Добавлен" << endl;
        break;
    default:
        break;
    }
    system("pause");
}

void Menu::save_to_file()
{
    system("cls");
    try
    {
        if (list.get_size() == 0)
        {
            throw "Нечего сохранять";
        }
        list.save();
        cout << "Сохранено" << endl;
    }
    catch (const char* ex) { cout << ex << endl; }
    system("pause");
}

void Menu::load_from_file()
{
    system("cls");
    try
    {
        list.load();
        cout << "Загружено" << endl;
    }
    catch (const char* ex) { cout << ex << endl; }
}

void Menu::delete_University()
{
    int c2;
    system("cls");
    cout << "Что хотите удалить? " << list.get_size() << endl;
    for (int i = 0; i < list.get_size(); i++)
    {
        cout << "_" << endl;
        cout << i + 1 << "|";
        list[i]->show();
    }
    cout << "->  ";
    cin >> c2;
    c2 = list.get_size() - c2 + 1;
    try {
        if ((c2 < 1) || (c2 > list.get_size()))
        {
            throw "Неверный номер";
            exception;
        }
        list.remove(c2 - 1);
        system("pause");
    }
    catch (const char* i)
    {
        cout << i << endl;
    }
}

void Menu::exit_from_programm()
{
    exit = 0;
}
