#include "Keeper.h"

void Keeper::saveUniversity(const University& university) {
    std::ofstream file("university.txt", std::ios::app);
    if (!file.is_open()) {
        throw UniversityException("Ошибка: не удалось открыть файл!");
    }
    for (int i = 0; i < university.studentCount; i++) {
        const University::Student* student = university.students[i];
        file << "Студент: " << student->getName() << std::endl;
        file << "Группа: " << student->getGroup() << std::endl;
        file << "Специальность: " << student->getSpecialty() << std::endl;
        file << "Курс: " << student->getCourse() << std::endl;
        file << "Средний балл: " << student->getAverageGrade() << std::endl;
        file << "----------------------\n";
    }

    for (int i = 0; i < teacherCount; i++) {
        const University::Teacher* teacher = teachers[i];
        file << "Преподаватель: " << teacher->getName() << std::endl;
        file << "Группы: ";
        for (int j = 0; j < teacher->getGroupCount(); j++) {
            file << teacher->getGroups()[j] << " ";
        }
        file << std::endl;
        file << "Предметы: ";
        for (int j = 0; j < teacher->getSubjectCount(); j++) {
            file << teacher->getSubjects()[j] << " ";
        }
        file << std::endl << std::endl;
    }
    for (int i = 0; i < university.staffCount; i++) {
        const University::Staff* staffMember = university.staff[i];
        file << "Административный персонал: " << staffMember->getName() << std::endl;
        file << "Должность: " << staffMember->getPosition() << std::endl;
        file << "Телефон: " << staffMember->getPhone() << std::endl;
        file << "Область ответственности: " << staffMember->getResponsibility() << std::endl;
        file << "----------------------\n";
    }
    file.close();
}

void Keeper::removeUniversityData() {
    std::ofstream file("university.txt");
    if (!file.is_open()) {
        throw UniversityException("Ошибка: не удалось открыть файл!");
    }
    file.close();
}