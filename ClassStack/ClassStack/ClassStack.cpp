#include <iostream>
#include <string>
#include "Stack.h"
#include "Calculator.h"

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

// печать целого числа по основанию B
void MultibaseOutput(long num, int B) {
	long temp = num;
	Stack<float> S;
	// извлечение чисел с основанием В справа налево
	//и помещение их в стек S
	do
	{
		S.Push(int(num % B));
		num /= B;
	} while (num != 0);
	cout << "Число " << temp << " в " << B << "-чной СС: ";
	while (!S.isEmpty())
		cout << S.Pop();
}

int main()
{
	setlocale(0, "");
	Stack<char> stack;
	bool isPalindrome = true;
	string str;
	char symbol;
	float number;
	int base;

	cout << "Введите строку: ";
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

		if (isPalindrome)
			cout << "Строка \"" << str << "\" является палиндромом\n\n";
		else
			cout << "Строка \"" << str << "\" не является палиндромом\n\n";
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

	cout << "Введите число и его основание через пробел:" << endl;
	cin >> number >> base;
	MultibaseOutput(number, base);
	cout << "\n\n";

	Calculator calc;
	calc.Run();
	cout << endl;
	
	system("pause");
	return 0;
}