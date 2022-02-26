#pragma once
class OurStack
{
private:
	//������ ������� �������� � ������ �����
	int data;
	//��������� �� ��������� �������
	OurStack* prev;
	public:
		OurStack();
		OurStack* del();
		OurStack(int value);
		/// <summary>
		/// ������� ��� ��������� �������� � ������ �����
		/// </summary>
		/// <param name="value">���� �������� ��� ���������</param>
		/// <returns>���������� ������, ���� �� ������ �������</returns>
		void push(int value);
		/// <summary>
		/// ���������� �������� �� �����
		/// </summary>
		/// <returns>���� �������� �� �����</returns>
		int pop();
};

