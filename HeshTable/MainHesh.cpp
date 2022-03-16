#include <iostream>
#include "HeshTable.h"
using namespace std;


int main() {
	const int rasm = 100;
	HeshTable ht(3);
	ht.add({ "Efimov", "Vova","Rafimov",5 });
	ht.add({ "Serg", "Vita","Schas",15 });
	ht.add({ "Chup", "Ura","Ratovich",15 });
	ht.add({ "Stolp", "Lexa","Serg",15 });
	ht.remove("Stolp", "Lexa", "Serg");
	return 0;
}