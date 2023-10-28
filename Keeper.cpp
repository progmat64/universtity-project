#pragma warning( disable : 6386 )
#pragma warning( disable : 26451 )
#include "Library.h"

using namespace std;

Keeper::Keeper() : m_size(0), head(nullptr) {}
Keeper::Keeper(int size) : head(nullptr) { this->m_size = size; }

Keeper::~Keeper()
{
	if (head != NULL)
	{
		Element* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~University();
			delete(buffer);
		}
		head->m_data->~University();
		delete(head);
	}
}

University* Keeper::operator[](const int index)
{
	if ((index >= m_size) || index < 0)
	{
		throw "Неверный индекс";
	}
	else
	{
		Element* buffer = head;
		for (int i = 0; i < m_size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->m_data);
	}
}

int Keeper::get_size() { return m_size; }

void Keeper::insert(University* new_data)
{
	Element* tmp;
	tmp = new Element;
	if (m_size == 0)
	{
		tmp->m_data = new_data;
		tmp->next = 0;
		++m_size;
	}
	else
	{
		tmp->m_data = new_data;
		tmp->next = head;
		++m_size;
	}
	head = tmp;
}

void Keeper::remove(int index)
{
	if ((head != NULL) && (index < m_size) && (index >= 0))
	{
		Element* tmonst = head, * helping = head;

		for (int i = 0; i < index; i++)
		{
			helping = tmonst;
			tmonst = tmonst->next;
		}

		if (tmonst == head)
		{
			head = tmonst->next;
		}
		else
		{
			helping->next = tmonst->next;
		}
		tmonst->m_data->~University();
		delete(tmonst);
		m_size--;
	}

}

void Keeper::save()
{
	setlocale(LC_ALL, "Russian");
	ofstream outfile;
	string initfile = "university.txt";
	try {
		outfile.open(initfile);
		if (!outfile) {
			throw std::runtime_error("Error while opening file " + initfile + " to save data.");
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
	outfile << m_size << endl;
	outfile.close();


	Element* buffer = head;
	for (int i = 0; i < m_size; i++)
	{
		buffer->m_data->saving();
		buffer = buffer->next;
	}
	system("university.txt");
}

void Keeper::load()
{
	setlocale(LC_ALL, "Russian");
	if (m_size != 0)
	{
		Element* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~University();
			delete(buffer);
		}
		head->m_data->~University();
		delete(head);
	}

	ifstream infile;
	int read_size, num_University;
	string a, b, c, d, e;
	string initfile = "university.txt";
	University* human;

	infile.open(initfile);
	if (!infile)
	{
		throw "ошибка открытия ";
		system("pause");
		exit(1);
	}

	infile >> read_size;

	for (int i = 0; i < read_size; i++)
	{
		infile >> num_University;
		infile.ignore(32767, '\n');

		if (num_University == 1)
		{
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			Student* student;
			student = new Student;
			student->set_name(a);
			student->set_group(b);
			student->set_specialty(c);
			student->set_course(d);
			student->set_averageGrade(e);
			human = student;
			insert(human);
		}

		if (num_University == 2)
		{
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			Teacher* teacher;
			teacher = new Teacher;
			teacher->set_name(a);
			teacher->set_groups(b);
			teacher->set_subjects(c);
			human = teacher;
			insert(human);
		}

		if (num_University == 3)
		{
			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			Staff* canselar;
			canselar = new Staff;
			canselar->set_name(a);
			canselar->set_position(b);
			canselar->set_phone(c);
			canselar->set_responsibility(d);
			human = canselar;
			insert(human);
		}
	}
}
