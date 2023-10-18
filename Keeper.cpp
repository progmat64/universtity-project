#include "Keeper.h"

void Keeper::saveUniversity(const University& university) {
    std::ofstream file("university.txt", std::ios::app);
    if (!file.is_open()) {
        throw UniversityException("������: �� ������� ������� ����!");
    }
    for (int i = 0; i < university.studentCount; i++) {
        const University::Student* student = university.students[i];
        file << "�������: " << student->getName() << std::endl;
        file << "������: " << student->getGroup() << std::endl;
        file << "�������������: " << student->getSpecialty() << std::endl;
        file << "����: " << student->getCourse() << std::endl;
        file << "������� ����: " << student->getAverageGrade() << std::endl;
        file << "----------------------\n";
    }

    for (int i = 0; i < teacherCount; i++) {
        const University::Teacher* teacher = teachers[i];
        file << "�������������: " << teacher->getName() << std::endl;
        file << "������: ";
        for (int j = 0; j < teacher->getGroupCount(); j++) {
            file << teacher->getGroups()[j] << " ";
        }
        file << std::endl;
        file << "��������: ";
        for (int j = 0; j < teacher->getSubjectCount(); j++) {
            file << teacher->getSubjects()[j] << " ";
        }
        file << std::endl << std::endl;
    }
    for (int i = 0; i < university.staffCount; i++) {
        const University::Staff* staffMember = university.staff[i];
        file << "���������������� ��������: " << staffMember->getName() << std::endl;
        file << "���������: " << staffMember->getPosition() << std::endl;
        file << "�������: " << staffMember->getPhone() << std::endl;
        file << "������� ���������������: " << staffMember->getResponsibility() << std::endl;
        file << "----------------------\n";
    }
    file.close();
}

void Keeper::removeUniversityData() {
    std::ofstream file("university.txt");
    if (!file.is_open()) {
        throw UniversityException("������: �� ������� ������� ����!");
    }
    file.close();
}