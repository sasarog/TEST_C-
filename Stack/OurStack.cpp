#include "OurStack.h"
#include <iostream>
using namespace std;
OurStack::OurStack()
{

}

OurStack* OurStack::del()
{
	return this;
}

OurStack::OurStack(int value)
{
	this->data = value;
}

void OurStack::push(int value)
{
	//Создаём новый элемент
	OurStack* newStack = new OurStack();
	//помещаем туда значение из головы стека
	newStack->data = this->data;

	//И ссылку предыдущего туда же.
	newStack->prev = this->prev;
	//В голову записываем новое значение
	this->data = value;
	//В качестве предыдущего вписываем только что созданный элемент
	this->prev = newStack;

}

int OurStack::pop()
{
	//Проверяем, что стек не пустой
	if (prev == nullptr) {
		throw  "No elem" ;
	}
	//запоминаем данные для вывода
	int result = this->data;
	//В голову в качестве значения записываем значение предыдущего
	this->data = prev->data;
	//Запоминаем адрес предыдущего, чтобы было что удалять
	OurStack* toDelete = this->prev;
	//В голову в качестве предыдущего записываем пред-предыдущий
	this->prev = prev->prev;
	//Удаляем предыдущий
	delete toDelete;
	//Возвращаем результат
	return result;
}
