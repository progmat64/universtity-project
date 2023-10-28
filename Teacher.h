#pragma once
#include "Library.h"
class Teacher :
    public University
{
private:
    string name;
    string groups;
    string subjects;

public:
    Teacher();
    ~Teacher();

    Teacher(const Teacher& Textbook_copy);
    Teacher(string name);

    string get_name() const;
    void set_name(string name_ch);

    string get_groups() const;
    void set_groups(string groups_ch);

    string get_subjects() const;
    void set_subjects(string subjects_ch);

    virtual void show();
    virtual void rewrite();
    virtual void saving();
    virtual void redact_str(int num_str, string red_str);
};
