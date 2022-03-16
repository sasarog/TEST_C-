#include "HeshTable.h"
#include <iostream>
using namespace std;

void HeshTable::add(Pipl pipl)
{
	cout << pipl.F << "adding by index" << heshPipl(pipl) << endl;
	table[heshPipl(pipl)].add(pipl);
}

bool HeshTable::consist(Pipl pipl)
{
	//if(table[heshPipl(pipl)].get() != )
	return false;
}

int HeshTable::heshPipl(Pipl p)
{
	int heshResult = 0;
	for (int i = 0; i < p.F.length(); i++) {
		heshResult += p.F[i];
		while (heshResult >= rasm) {
			heshResult = heshResult / p.F.length();
		}
	}
	for (int i = 0; i < p.I.length(); i++) {
		heshResult += p.I[i];
		while (heshResult >= rasm) {
			heshResult = heshResult / p.I.length();
		}
	}
	for (int i = 0; i < p.O.length(); i++) {
		heshResult += p.O[i];
		while (heshResult >= rasm) {
			heshResult = heshResult / p.O.length();
		}
	}
	return heshResult;
}

HeshTable::HeshTable(int count)
{
	table = new Spisok[count];
	this->rasm = count;
}

void HeshTable::remove(string f, string i, string o)
{
	Pipl toDelete = { f,i,o,0 };
	table[this->heshPipl(toDelete)].remove(f, i, o);
}

Spisok* Spisok::findAddr(string f, string i, string o)
{
	if (
		pip->F == f &&
		pip->I == i &&
		pip->O == o
		) {
		return this;
	}
	else {
		if (this->next != NULL) {
			this->next->findAddr(f, i, o);
		}
		else {
			return NULL;
		}
	}
}

void Spisok::add(Pipl ad)
{
	if (this->pip == NULL) {
		pip = new Pipl(ad);
		return;
	}
	else {
		if (this->next == NULL) {
			Spisok* newElem = new Spisok();
			newElem->pip = new Pipl(ad);
			this->next = newElem;
			
			return;
		}
		else {
			next->add(ad);
		}
	}
}

void Spisok::suicide()
{
	//добавить проверку на существование элемента
	delete this->pip;
	this->pip = NULL;
	if (this->next) {
		this->pip = next->pip;
		Spisok* toDelete = this->next;
		this->next = this->next->next;
		delete toDelete;
	}	
}

Pipl Spisok::get()
{
	Pipl out;
	out.age = pip->age;
	out.F = pip->F;
	out.I = pip->I;
	out.O = pip->O;
	return out;
}

void Spisok::remove(string f, string i, string o)
{
	Spisok* todelete = this->findAddr(f, i, o);
	todelete->suicide();
}

Pipl Spisok::find(string f, string i, string o)
{
	if (
		pip->F == f &&
		pip->I == i &&
		pip->O == o
		) {
		return this->get();
	}
	else {
		if (this->next != NULL) {
			this->next->find(f, i, o);
		}
		else {
			return Pipl();
		}
	}
}
