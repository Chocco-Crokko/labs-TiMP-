/*
\file
\brief заголовочный файл, реализующий структуру данных очередь
\warning данна€ структура реализована исключительно в учебных цел€х
*/
#include <stdexcept>
#include "Interface.h"

template <class T = int>
class Queue : public IQ<T>
{
	bool isFull;
	const size_t size;
	size_t top_, bottom;
	T *arr;
public:
	Queue(size_t n = 100)
		: isFull(false), size(n), top_(0), bottom(0), arr(new T[size])
	{
	}
	/*
	\brief провер€ет очередь на пустоту
	\return bool-значение, показывающее, пуста€ ли очередь
	*/
	bool empty()
	{
		return top_ == bottom && !isFull;
	}
	/*
	\brief добавл€ет значение в конец очереди
	\param val значение, которое нужно добавить

	‘ункци€ выполн€етс€ только если очередь не полна€
	*/
	void push(const T &val) {
		if (isFull)
			return;
		arr[bottom] = val;
		bottom = (bottom + 1) % size;
		if (top_ == bottom)
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
		top_ = (top_ + 1) % size;
	}
	/*
	\brief возвращает начало очереди
	\return значение, наход€щеес€ в начале очереди

	‘ункци€ выполн€етс€ только если очередь не пуста€.
	*/
	T &top() {
		if (!empty())
			return arr[top_];
		else
			throw std::out_of_range("queue is empty");
	}

	~Queue() {
		delete[] arr;
	}
};


extern "C"
{
	__declspec(dllexport) IQ<> *GetSomeIQ()
	{
		return new Queue<>();
	}
}

