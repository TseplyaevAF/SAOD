#pragma once

const unsigned MAX_STACK_SIZE = 100; // максимальна¤ длина стека

template <typename T>
class Stack
{
private:
	T stack_list[MAX_STACK_SIZE]; // массив из данных стека
	int top; // индекс вершины стека

public:
	// »сключени¤
	enum ERRORS {
		stack_overflow = -1, // переполнение стека
		stack_isEmpty = -2, // стеку пуст
	};

	// конструктор инициализирует вершину стека
	Stack() : top(-1) { }

	// добавить элемент в вершину
	void Push(T item) {
		// если стек полный, завершить выполнение программы
		if (top == MAX_STACK_SIZE - 1)
			throw stack_overflow;
		// иначе, увеличить вершину на 1
		top++;
		//добавить элемент в массив
		stack_list[top] = item;
	}

	// изъ¤ть элемент из вершины
	T Pop(void) {
		T temp;
		// если стек пуст
		if (top == -1)
			throw stack_isEmpty;
		temp = stack_list[top];
		// уменьшить длину стека на 1
		top--;
		// вернуть элемент из вершины стека
		return temp;
	}

	// очистить стек
	void Clear(void) {
		top = -1;
	}

	// вернуть элемент, не удал¤¤ из вершины
	T Peek(void) const {
		if (top == -1)
			throw stack_isEmpty;
		return stack_list[top];
	}

	// проверка на пустоту
	bool isEmpty() const {
		// если стек пуст, вернуть true, иначе false
		return top == -1 ? true : false;
	}
};