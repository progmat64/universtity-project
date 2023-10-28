#pragma once
#include "Library.h"

using namespace std;

class University
{
public:
	University() {};
	virtual ~University() {};
	virtual void show() = 0;
	virtual void rewrite() = 0;
	virtual void saving() = 0;
	virtual void redact_str(int num_str, string red_str) = 0;

};

typedef struct Element
{
	University* m_data;
	Element* next;
} Element;
