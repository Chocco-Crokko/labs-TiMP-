#pragma once
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
/*
\file
\brief заголовочный файл, реализующий структуру данных очередь
\warning данна€ структура реализована исключительно в учебных цел€х
*/
template <class T>
class Queue
{
	mutable bool isFull;
	const size_t size;
	size_t top, bottom;
	T *arr;
public:
	Queue(size_t n = 100)
		: isFull(false), size(n), top(0), bottom(0), arr(new T[size])
	{
	}
	/*
	\brief провер€ет очередь на пустоту
	\return bool-значение, показывающее, пуста€ ли очередь
	*/
	bool empty() const
	{
		return top == bottom && !isFull;
	}
	/*
	\brief добавл€ет значение в конец очереди
	\param val значение, которое нужно добавить

	‘ункци€ выполн€етс€ только если очередь не полна€
	*/
	void push(T val) {
		if (isFull)
			return;
		arr[bottom] = val;
		bottom = (bottom + 1) % size;
		if (top == bottom)
			isFull = true;
	}
	/*
	\brief удал€ет значение из начала очереди

	‘ункци€ выполн€етс€ только если очередь не пуста€. —брасывает флаг того, что очередь полна€
	*/
	void pop() {
		if (empty())
			return;
		isFull = false;
		top = (top + 1) % size;
	}
	/*
	\brief возвращает начало очереди
	\return значение, наход€щеес€ в начале очереди

	‘ункци€ выполн€етс€ только если очередь не пуста€.
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