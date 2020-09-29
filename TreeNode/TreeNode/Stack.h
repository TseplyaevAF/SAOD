#pragma once

const unsigned MAX_STACK_SIZE = 100; // ����������� ����� �����

template <typename T>
class Stack
{
private:
	T stack_list[MAX_STACK_SIZE]; // ������ �� ������ �����
	int top; // ������ ������� �����

public:
	// ���������
	enum ERRORS {
		stack_overflow = -1, // ������������ �����
		stack_isEmpty = -2, // ����� ����
	};

	// ����������� �������������� ������� �����
	Stack() : top(-1) { }

	// �������� ������� � �������
	void Push(T item) {
		// ���� ���� ������, ��������� ���������� ���������
		if (top == MAX_STACK_SIZE - 1)
			throw stack_overflow;
		// �����, ��������� ������� �� 1
		top++;
		//�������� ������� � ������
		stack_list[top] = item;
	}

	// ������ ������� �� �������
	T Pop(void) {
		T temp;
		// ���� ���� ����
		if (top == -1)
			throw stack_isEmpty;
		temp = stack_list[top];
		// ��������� ����� ����� �� 1
		top--;
		// ������� ������� �� ������� �����
		return temp;
	}

	// �������� ����
	void Clear(void) {
		top = -1;
	}

	// ������� �������, �� ���뤤 �� �������
	T Peek(void) const {
		if (top == -1)
			throw stack_isEmpty;
		return stack_list[top];
	}

	// �������� �� �������
	bool isEmpty() const {
		// ���� ���� ����, ������� true, ����� false
		return top == -1 ? true : false;
	}
};