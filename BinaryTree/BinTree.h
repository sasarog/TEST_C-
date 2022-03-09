#pragma once
#include <iostream>
class BinTree
{
	int data = NULL;
	BinTree* left = NULL;
	BinTree* right = NULL;
	BinTree* findMin();
	BinTree* poisk(int value);
	void deleteBy(int value, BinTree* papa);
public:
	void add(int value);
	bool consist(int poisk);
	bool deleteElem(int value);

};

