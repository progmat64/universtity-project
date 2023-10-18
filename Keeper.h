#pragma once
#include "University.h"
#include <fstream>

class Keeper : University {
public:
    void saveUniversity(const University& university);
    void removeUniversityData();
};