#include <iostream>
#include "BinTree.h"
using namespace std;

int main() {
	BinTree tree;
	tree.add(35);
	tree.add(50);
	tree.add(60);
	cout << endl << tree.consist(61) << endl;
	return 0;
}