#pragma once
class OurStack
{
private:
	//Данные которые хранятся в ячейке стека
	int data;
	//Указатель на следующий элемент
	OurStack* prev;
	public:
		OurStack();
		OurStack* del();
		OurStack(int value);
		/// <summary>
		/// Функция для помещения значения в ячейку стека
		/// </summary>
		/// <param name="value">Само значение для помещения</param>
		/// <returns>Возвращать истину, есои всё прошло успешно</returns>
		void push(int value);
		/// <summary>
		/// Возвращает значение из стека
		/// </summary>
		/// <returns>Само значение из стека</returns>
		int pop();
};

