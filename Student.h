#pragma once
#include "Library.h"
class Student : public University
{
private:
	string name;
	string group;
	string specialty;
	string course;
	string averageGrade;

public:
	Student();
	Student(string name);
	~Student();
	Student(const Student& Student_copy);

	string get_name() const;
	void set_name(string name_ch);

	string get_group() const;
	void set_group(string group_ch);

	string get_specialty() const;
	void set_specialty(string specialty_ch);

	string get_course() const;
	void set_course(string course_ch);

	string get_averageGrade() const;
	void set_averageGrade(string averageGrade_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);

};
