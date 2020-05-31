#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string>

// ����� ������
class String
{
	char* str; // ���������� ������ ��� ������������� ������
	int size; // ����� �������

public:
	enum ERRORS { outOfMemory = -1 };

	// �. �� ���������, ������ ������ � ����� ������� ����
	String();

	// �����������, �������� ������ � �������� � ������ C++
	String(char* s);

	// �������� ������������
	String& operator=(const String& s);

	// ������� ������ �� �������
	char getSymbol(int index) const;

	// ������ ������ �� �������
	void setSymbol(int index, char symbol);

	// ������� ����� ������
	int getSize() const {
		return size;
	}

	char* getStr();

	// �������� ��������� ���� �������� String
	friend int operator== (const String& s1, const String& s2)
	{
		return strcmp(s1.str, s2.str) == 0;
	}

	// ���������� ��������� � ������� index � ������ count
	String Substr(int index, int count) const;

	// ���� ������
	void ReadString();

	// ����� ��������� ������� � ������, ������� � ������� start
	int Find(char c, int start) const;
};