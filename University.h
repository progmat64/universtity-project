#pragma once
#include <iostream>
#include <cstring>

class UniversityException : public std::exception {
public:
    UniversityException(const char* message) : std::exception(message) {}
};

class University {
public:
    University();
    ~University();

    void printStudents();
    void printTeachers();
    void printStaff();

    class Student {
    public:
        Student(const char* name, const char* group, const char* specialty, int course, double averageGrade);
        ~Student();

        void print();
        void setName(const char* name);
        void setGroup(const char* group);
        void setSpecialty(const char* specialty);
        void setCourse(int course);
        void setAverageGrade(double averageGrade);

        const char* getName() const;
        const char* getGroup() const;
        const char* getSpecialty() const;
        int getCourse() const;
        double getAverageGrade() const;

    private:
        char* name;
        char* group;
        char* specialty;
        int course;
        double averageGrade;
    };

    void removeStudent();
    void addStudent();

    class Teacher {
    public:
        Teacher(const char* name, const char** groups, int groupCount, const char** subjects, int subjectCount);
        ~Teacher();

        void print();
        void setName(const char* name);
        void setGroups(const char** groups, int groupCount);
        void setSubjects(const char** subjects, int subjectCount);

        const char* getName() const;
        char** getGroups() const;
        int getGroupCount() const;
        char** getSubjects() const;
        int getSubjectCount() const;

    private:
        char* name;
        char** groups;
        int groupCount;
        char** subjects;
        int subjectCount;
    };

    void addTeacher();
    void removeTeacher(int index);

    class Staff {
    public:
        Staff(const char* name, const char* position, const char* phone, const char* responsibility);
        ~Staff();

        void setName(const char* name);
        void setPosition(const char* position);
        void setPhone(const char* phone);
        void setResponsibility(const char* responsibility);

        void print();

        const char* getName() const;
        const char* getPosition() const;
        const char* getPhone() const;
        const char* getResponsibility() const;

    private:
        char* name;
        char* position;
        char* phone;
        char* responsibility;
    };

    void addStaff();
    void removeStaff(int index);


    Student** students;
    int studentCount;
    Teacher** teachers;
    int teacherCount;
    Staff** staff;
    int staffCount;
};