#include "BinTree.h"

BinTree* BinTree::findMin()
{
	//Если слева не пусто, идем влево
	if (left != NULL) {
		return left->findMin();
		//если слева пусто, то это мин. элемент, который нужно вернуть
	}
	else {
		return this;
	}
}

BinTree* BinTree::poisk(int value)
{
	if (value == data)
		return this;
	if (value > data) {
		return right->poisk(value);
	}
	else {
		return left->poisk(value);
	}

}

void BinTree::deleteBy(int value, BinTree* papa)
{
	
	if (this->data == value) {
		//Листок
		if (left == NULL && right == NULL) {
			if (papa->left == this) {
				papa->left = NULL;
			}
			else {
				papa->right = NULL;
			}
			delete this;
			return;
		}
		//Один ребёнок
		if (papa->left == this) {
			papa->left = left == NULL ? right : left;
		}
		else {
			papa->right = left == NULL ? right : left;
		}
		delete this;
		return;
		// Два ребёнка
		BinTree* smena = right;
		BinTree* smenaPapa = right;
		while (smena->left != NULL)
		{
			smenaPapa = smena;
			smena = smena->left;
		}
		this->data = smena->data;
		delete smena;
		smenaPapa->left = NULL;
		
	}
	else {
		if (value > data) {
			right->deleteBy(value, this);
		}
		else {
			left->deleteBy(value, this);
		}		
	}
}

void BinTree::add(int value)
{
	if (data == NULL) {
		data = value;
		return;
	}
	//Если значение больше, идём в правую ветку
	if (value > data) {
		//Если справа не пусто, переходим туда
		if (right != NULL) {
			right->add(value);
			return;
		}
		//Если пусто, создаём новый узел
		else {
			BinTree* newElem = new BinTree;
			newElem->data = value;
			this->right = newElem;
			return;
		}
	}
	//Если значение меньше, идём в левую ветку
	else {
		//Если справа не пусто, переходим туда
		if (left != NULL) {
			left->add(value);
			return;
		}
		//Если пусто, создаём новый узел
		else {
			BinTree* newElem = new BinTree;
			newElem->data = value;
			left = newElem;
			return;
		}
	}
}

bool BinTree::consist(int poisk)
{
	//Если данные в узле соответствуют искомому, возвр истину
	if (data == poisk) {
		return true;
	}
	//Если искомое число больше, идём в правую ветку
	if (poisk > data) {
		//Емли справа пустота, то искомого числа нет, возвр false
		if (right == NULL) return false;
		return right->consist(poisk);
	}
	//Если меньше, идём в левую ветку
	else {
		//Если слева пусто, искомого числа нет
		if (left == NULL) return false;
		return left->consist(poisk);
	}
}

bool BinTree::deleteElem(int value)
{


	return false;
}
