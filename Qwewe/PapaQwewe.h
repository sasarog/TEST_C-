#pragma once
struct Qwewe {

	Qwewe* left = nullptr;
	Qwewe* right = nullptr;
	int data;
};
class PapaQwewe
{
	Qwewe* current = nullptr;
public: 
	/// <summary>
	/// ���������� ��������� �����
	/// </summary>
	void goLeft();
	/// <summary>
	/// ���������� ��������� ������
	/// </summary>
	void goRight();
	/// <summary>
	/// ���������� ��������
	/// </summary>
	/// <param name="value">���� ��������, ������� ��������� � ������</param>
	void add(int value);
	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <returns>���������� �������� ������, �� ������� ��������� ���������</returns>
	int getValue();
	/// <summary>
	/// ������� ��� �������� ������ ������-������
	/// </summary>
	void printLeftToRight();
	/// <summary>
	/// ������� ������� �������.
	/// </summary>
	void deleteElem();
};

