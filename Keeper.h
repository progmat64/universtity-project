#pragma once
#include "Library.h"

class Keeper
{
private:
	int m_size = 0;
	Element* head = NULL;
public:
	Keeper();
	Keeper(int size);
	~Keeper();

	University* operator[] (int index);

	int get_size();
	void insert(University* n_data);
	void remove(int index);
	void save();
	void load();
};
