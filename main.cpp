#include "Library.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Μενώ" << endl;
	Menu menu;
	menu.main_menu();
	return 0;
}
