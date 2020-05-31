#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>

// Класс Строка
class String
{
	char* str; // символьный массив для представления строки
	int size; // длина массива

public:
	enum ERRORS { outOfMemory = -1 };

	// к. по умолчанию, задает строку и длину равными нулю
	String();

	// конструктор, выделяет память и копирует в строку C++
	String(char* s);

	// оператор присваивания
	String& operator=(const String& s);

	// вернуть символ по индексу
	char getSymbol(int index) const;

	// задать символ по индексу
	void setSymbol(int index, char symbol);

	// вернуть длину строки
	int getSize() const {
		return size;
	}

	char* getStr();

	// оператор сравнения двух объектов String
	friend int operator== (const String& s1, const String& s2)
	{
		return strcmp(s1.str, s2.str) == 0;
	}

	// возвращает подстроку с позиции index и длиной count
	String Substr(int index, int count) const;

	// ввод строки
	void ReadString();

	// поиск вхождения символа в строке, начиная с позиции start
	int Find(char c, int start) const;
};