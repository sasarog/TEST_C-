#include "PapaQwewe.h"
#include <iostream>
using namespace std;
void PapaQwewe::goLeft()
{
	//���� ����� �� �����, ����������� �����
	if (current->left != nullptr)
		current = current->left;
}
void PapaQwewe::goRight()
{
	//���� ������ �� �����, ��� ������
	if (current->right != nullptr)
		current = current->right;
}
void PapaQwewe::add(int value)
{
	//��������� ������ ������ �� ������� �������
	//������ ����� ������� ��� ����������
	Qwewe* newElem = new Qwewe;
	newElem->data = value;
	//���� ��������� � ������ ������
	if (!current) {
		current = newElem;
		return;
	}
	//���� � ������ ������ ���� �������
	if (current->right == NULL) {
		newElem->left = current;
		current->right = newElem;
		return;
	}
	//���� � ������ ��� � ������ ���������
	else {
		current->right->left = newElem;
		newElem->right = current->right;
		newElem->left = current;
		current->right = newElem;
		return;
	}
}

int PapaQwewe::getValue()
{
	//���������� �������� ������ �� ������� �������
	return current->data;
}

void PapaQwewe::printLeftToRight()
{
	//��� � ����� ����� ����
	while (current->left != NULL) {
		goLeft();
	}
	//������� ���� ����� ����� �������
	cout << current->data << ' ';
	//������� �� �����-���������
	while (current->right != NULL) {
		goRight();
		cout << current->data << ' ';

	}
}

void PapaQwewe::deleteElem()
{
	//���� ������ ������, ������ �� ������, ������� ������
	if (current == NULL) {
		return;
	}
	//���� � ������ ������ ���� �������
	if (current->left == current->right) {
		if (current != NULL) {
			delete current;
			current = NULL;
		}
		return;
	}
	//���� � ������ ��� � ����� ���������
	Qwewe* toDelete = current;
	//� ����������� �� ����, ���� �� �������� ������ � �����,
	//��� �������� ������������� ������ ������
	if (current->right != NULL) {
		current->right->left = current->left;
	}
	if (current->left != NULL) {
		current->left->right = current->right;
	}
	if (current->right != NULL) {
		current = current->right;
	}
	else {
		if (current->left != NULL) {
			current = current->left;
		}
	}

	delete toDelete;
}
