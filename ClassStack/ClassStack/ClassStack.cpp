#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

// удалить пробелы из строки
void DeleteSpaces(string &s) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			s.erase(i, 1);
			i--;
		}
	}
}

int main()
{
	setlocale(0, "");
	Stack<char> stack;
	bool isPalindrome = true;
	string str;
	char symbol;
	cout << "Введите строку" << endl;
	getline(cin, str);
	DeleteSpaces(str); // очистить строку от пробелов

	try 
	{
		// поместить символы выражения без пробелов в стек
		int i = 0;
		while (str[i] != 0)
		{
			stack.Push(str[i]);
			i++;
		}

		i = 0;
		while (!stack.isEmpty()) {
			symbol = stack.Pop();
			if (symbol != str[i]) {
				isPalindrome = false;
				break;
			}
			i++;
		}

		if (isPalindrome) {
			cout << "Строка является палиндромом" << "\n\n";
		}

	}
	catch (Stack<char>::ERRORS e) 
	{
		if (e == Stack<char>::stack_isEmpty)
		{
			cout << "Стек пуст!" << endl;
		}
		if (e == Stack<char>::stack_overflow)
		{
			cout << "Стек перполнен! Добавить данные невозможно." << endl;
		}
	}
	

	system("pause");
	return 0;
}
