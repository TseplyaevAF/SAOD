#pragma once

const unsigned MAX_QUEUE_SIZE = 50; // максимальная длина очереди

template <typename T>
class Queue
{
private:
	int front, // позиция первого элемента в очереди
		rear, // позиция последнего элемента в очереди
		count; // кол-во элементов очереди
	T qlist[MAX_QUEUE_SIZE]; // массив из данных очереди

public:
	// Исключения
	enum ERRORS {
		queue_overflow = -1, // переполнение очереди
		queue_isEmpty = -2, // очередь пуста
	};

	Queue() : front(0), rear(0), count(0)
	{}

	// вернуть кол-во элементов в очереди
	int QLength() const {
		return count;
	}

	// проверка очереди на пустоту
	bool QEmpty() const {
		return (QLength() == 0) ? true : false;
	}

	void QInsert(T item) {
		// бросить исключение, если очередь заполнена
		if (count == MAX_QUEUE_SIZE)
			throw queue_overflow;
		// увеличить count, присвоить значение item элементу массива
		// изменить значение rear
		count++;
		qlist[rear] = item;
		rear = (rear + 1) % MAX_QUEUE_SIZE;
	}

	T QDelete() {
		T temp;
		// если очередь пуста, бросить исключение
		if (QEmpty())
			throw queue_isEmpty;
		// записать значение в начало очереди
		temp = qlist[front];
		// уменьшить count на единицу
		// продвинуть начало очереди и возвратить прежнее значение
		// из начала
		count--;
		front = (front + 1) % MAX_QUEUE_SIZE;
		return temp;
	}

	// Вернуть первый элемент в очереди
	T QFront() const {
		// если очередь пуста, бросить исключение
		if (QEmpty())
			throw queue_isEmpty;
		return qlist[front];
	}

	void QClear() {
		front = 0;
		rear = 0;
		count = 0;
	}

};