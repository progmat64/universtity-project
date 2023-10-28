#pragma once
#include "Library.h"
class Staff : public University
{
private:
	string name;
	string position;
	string phone;
	string responsibility;

public:
	Staff();
	~Staff();
	Staff(const Staff& Staff_copy);
	Staff(string name);

	string get_name() const;
	void set_name(string name_ch);
	string get_position() const;
	void set_position(string position_ch);
	string get_phone() const;
	void set_phone(string phone_ch);

	string get_responsibility() const;
	void set_responsibility(string responsibility_ch);


	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
};
