/*!
 *\file
 *\brief Заголовочный файл с описанием класса
 
 *Данный файл содержит в себе определение
 класса структуры данных - очередь
 */

#pragma once
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
/*!
 *\brief Cтруктура данных очередь
 *\warning Данная структура реализована исключительно в учебных целях

 *Очередь, основанная на закольцованном массиве
 */
template <class T>
class Queue
{
	mutable bool isFull;
	const size_t size;
	size_t top, bottom;
	T *arr;
public:
	/*!
	 *\brief Стандартный конструктор
	 */
	Queue(size_t n = 100)
		: isFull(false), size(n), top(0), bottom(0), arr(new T[size])
	{
	}
	/*!
	 *\brief Проверка очереди на пустоту
	 *\return bool-значение, показывающее, пустая ли очередь
	 */
	bool empty() const
	{
		return top == bottom && !isFull;
	}
	/*!
	 *\brief Добавление значения в конец очереди
	 *\param val значение, которое нужно добавить

	 *Функция выполняется только если очередь не полная
	 */
	void push(T val) {
		if (isFull)
			return;
		arr[bottom] = val;
		bottom = (bottom + 1) % size;
		if (top == bottom)
			isFull = true;
	}
	/*!
	 *\brief Удаление значения из начала очереди

	 *Функция выполняется только если очередь не пустая. Сбрасывает флаг того, что очередь полная
	 */
	void pop() {
		if (empty())
			return;
		isFull = false;
		top = (top + 1) % size;
	}
	/*!
	 *\brief Возвращение элемента в начале очереди
	 *\return Значение, находящееся в начале очереди

	 *Функция выполняется только если очередь не пустая.
	 */
	T front() const {
		if (!empty())
			return arr[top];
		else 
			throw std::runtime_error("queue is empty");
	}
	~Queue() {
		delete[] arr;
	}
};


#endif // QUEUE_H_INCLUDED
