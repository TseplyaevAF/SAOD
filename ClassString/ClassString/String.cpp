#include "String.h"
#include <iostream>
#include <cstdlib>

String::String()
{
	str = 0;
	size = 0;
}

String::String(char* s) {
	size = strlen(s);
	str = new char[size];
	// программа завершается, если память исчерпана.
	if (str == nullptr)
		throw outOfMemory;
	strcpy(str, s);
}

char* String::getStr() {
	return str;
}

String& String::operator=(const String& s) {
	// если размеры различные, удаление текущей строки и выделение нового массива
	if (s.size != size)
	{
		delete[] str;
		str = new char[s.size];
		if (str == nullptr)
			throw outOfMemory;
		// назначение размера, равного размеру s
		size = s.size;
	}
	// копируется s.str и возвращается ссылка на текущий объект
	strcpy(str, s.str);
	return *this;
}

char String::getSymbol(int index) const {
	if (index < 0 || index > size)
		throw outOfMemory;
	return str[index];
}

void String::setSymbol(int index, char symbol) {
	if (index < 0 || index > size)
		throw outOfMemory;
	str[index] = symbol;
}

String String::Substr(int index, int count) const {
	if (index < 0 || index > size) throw outOfMemory;
	char* buf = new char[count + 1];
	buf[count] = '\0';
	int k = 0;

	for (int i = index; i < index + count; i++)
	{
		buf[k] = getSymbol(i);
		k++;
	}
	//strncpy(buf2, buf, count);
	String temp(buf);
	return temp;
}

void String::ReadString() {
	char temp[256]; // буфер
	std::cin.getline(temp, 256);
	size = strlen(temp);
	str = new char[size];
	strcpy(str, temp);
}

int String::Find(char c, int start) const {
	for (int i = 0; i <= size - 1; i++)
	{
		if (c == str[i]) return i;
	}
	return -1;
}