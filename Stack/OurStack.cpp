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
	//������ ����� �������
	OurStack* newStack = new OurStack();
	//�������� ���� �������� �� ������ �����
	newStack->data = this->data;

	//� ������ ����������� ���� ��.
	newStack->prev = this->prev;
	//� ������ ���������� ����� ��������
	this->data = value;
	//� �������� ����������� ��������� ������ ��� ��������� �������
	this->prev = newStack;

}

int OurStack::pop()
{
	//���������, ��� ���� �� ������
	if (prev == nullptr) {
		throw  "No elem" ;
	}
	//���������� ������ ��� ������
	int result = this->data;
	//� ������ � �������� �������� ���������� �������� �����������
	this->data = prev->data;
	//���������� ����� �����������, ����� ���� ��� �������
	OurStack* toDelete = this->prev;
	//� ������ � �������� ����������� ���������� ����-����������
	this->prev = prev->prev;
	//������� ����������
	delete toDelete;
	//���������� ���������
	return result;
}
