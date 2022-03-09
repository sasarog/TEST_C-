#include "BinTree.h"

BinTree* BinTree::findMin()
{
	//���� ����� �� �����, ���� �����
	if (left != NULL) {
		return left->findMin();
		//���� ����� �����, �� ��� ���. �������, ������� ����� �������
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
		//������
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
		//���� ������
		if (papa->left == this) {
			papa->left = left == NULL ? right : left;
		}
		else {
			papa->right = left == NULL ? right : left;
		}
		delete this;
		return;
		// ��� ������
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
	//���� �������� ������, ��� � ������ �����
	if (value > data) {
		//���� ������ �� �����, ��������� ����
		if (right != NULL) {
			right->add(value);
			return;
		}
		//���� �����, ������ ����� ����
		else {
			BinTree* newElem = new BinTree;
			newElem->data = value;
			this->right = newElem;
			return;
		}
	}
	//���� �������� ������, ��� � ����� �����
	else {
		//���� ������ �� �����, ��������� ����
		if (left != NULL) {
			left->add(value);
			return;
		}
		//���� �����, ������ ����� ����
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
	//���� ������ � ���� ������������� ��������, ����� ������
	if (data == poisk) {
		return true;
	}
	//���� ������� ����� ������, ��� � ������ �����
	if (poisk > data) {
		//���� ������ �������, �� �������� ����� ���, ����� false
		if (right == NULL) return false;
		return right->consist(poisk);
	}
	//���� ������, ��� � ����� �����
	else {
		//���� ����� �����, �������� ����� ���
		if (left == NULL) return false;
		return left->consist(poisk);
	}
}

bool BinTree::deleteElem(int value)
{


	return false;
}
