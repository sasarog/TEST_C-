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
	/// Перемещает указатель влево
	/// </summary>
	void goLeft();
	/// <summary>
	/// Перемещает указатель вправо
	/// </summary>
	void goRight();
	/// <summary>
	/// Добавление значения
	/// </summary>
	/// <param name="value">Само значение, которое добавляем в список</param>
	void add(int value);
	/// <summary>
	/// Получить значение
	/// </summary>
	/// <returns>Возвращает значение ячейки, на которой находится указатель</returns>
	int getValue();
	/// <summary>
	/// Выводит все элементы списка справа-налево
	/// </summary>
	void printLeftToRight();
	/// <summary>
	/// Удаляет текущий элемент.
	/// </summary>
	void deleteElem();
};

