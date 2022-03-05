#include "BinTree.h"

BinTree* BinTree::findMin()
{
	//���� ����� �� �����, ���� �����
	if (left != NULL) {
		return left->findMin();
		//���� ����� �����, �� ��� ���. �������, ������� ����� �������
	}else{
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
	if (value == data)
		return this;
	if (value > data) {
		return right->poisk(value);
	}
	else {
		return left->poisk(value);
	}


}
