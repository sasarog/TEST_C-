#include <iostream>
#include <Windows.h>
#include "PapaQwewe.h"	
using namespace std;
int main() {
	
	PapaQwewe papa;
	
	for (int i = 0; i < 10; i++) {
		papa.add(i);
	}
	papa.printLeftToRight();
	for (int i = 0; i < 20; i++) {
		papa.deleteElem();
	}
	papa.add(2);
	papa.add(4);
	papa.printLeftToRight();
	
	
	
	return 0;
}