#include "OurStack.h"
#include <iostream>

using namespace std;

int main() {
	OurStack* stack = new OurStack();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	try {
		cout << stack->pop() << ' ';
		cout << stack->pop() << ' ';
		cout << stack->pop() << ' ';
		cout << stack->pop() << ' ';
		cout << stack->pop() << ' ';
		cout << stack->pop() << ' ';
		cout << stack->pop() << ' ';
		cout << stack->pop() << ' ';
	}
	catch (const char* exception) {
		cerr << exception << endl;
	}
	return 0;
}