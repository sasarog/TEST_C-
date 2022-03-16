#pragma once
#include <iostream>
using namespace std;
struct Pipl
{
	string F;
	string I;
	string O;
	int age;
};
class Spisok
{
	Pipl* pip = NULL;
	Spisok* next = NULL;
	Spisok* findAddr(string f, string i, string o);
	void suicide();
public:
	void add(Pipl ad);
	void remove(string f, string i, string o);
	Pipl get();
	Pipl find(string f, string i, string o);
	
private:

};


class HeshTable
{
	int rasm;
	Spisok* table;
	int heshPipl(Pipl p);
public:
	HeshTable(int count);
	void add(Pipl pipl);
	bool consist(Pipl pipl);
	void remove(string f, string i, string o);


};

