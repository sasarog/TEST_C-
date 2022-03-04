#include "PapaQwewe.h"
#include <iostream>
using namespace std;
void PapaQwewe::goLeft()
{
	//Если слева не пусто, перемещаемя влево
	if (current->left != nullptr)
		current = current->left;
}
void PapaQwewe::goRight()
{
	//Если справа не пусто, идём вправо
	if (current->right != nullptr)
		current = current->right;
}
void PapaQwewe::add(int value)
{
	//Добавляем всегда вправо от текущей позиции
	//Создаём новый элемент для добавления
	Qwewe* newElem = new Qwewe;
	newElem->data = value;
	//Если добавляем в пустой список
	if (!current) {
		current = newElem;
		return;
	}
	//Если в списке только один элемент
	if (current->right == NULL) {
		newElem->left = current;
		current->right = newElem;
		return;
	}
	//Если в списке два и больше элементов
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
	//Возвращаем значение ячейки на текущей позиции
	return current->data;
}

void PapaQwewe::printLeftToRight()
{
	//Идём в самый левый конц
	while (current->left != NULL) {
		goLeft();
	}
	//Выводим этот самый левый элемент
	cout << current->data << ' ';
	//Выводим всё слева-наваправо
	while (current->right != NULL) {
		goRight();
		cout << current->data << ' ';

	}
}

void PapaQwewe::deleteElem()
{
	//Если список пустой, ничего не делаем, удалять нечего
	if (current == NULL) {
		return;
	}
	//Если в списке только один элемент
	if (current->left == current->right) {
		if (current != NULL) {
			delete current;
			current = NULL;
		}
		return;
	}
	//Если в списке два и боьше элементов
	Qwewe* toDelete = current;
	//В зависимости от того, есть ли элементы справа и слева,
	//при удалении пересвязываем ячейку списка
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
