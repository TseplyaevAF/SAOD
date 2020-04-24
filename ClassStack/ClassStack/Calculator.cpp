#include "Calculator.h"
#include <iostream>

void Calculator::AddTop(double num) {
	S.Push(num);
}

bool Calculator::GetTwoOperands(double& opndl, double& opnd2) {
	if (S.isEmpty()) // проверить наличие первого операнда
	{
		std::cout << "Отсутствует операнд 1!";
		return false;
	}
	opndl = S.Pop(); // извлечь правый операнд

	if (S.isEmpty()) // проверить наличие второго операнда 
	{
		std::cout << "Отсутствует операнд 2!";
		return false;
	}
	opnd2 = S.Pop(); // извлечь левый операнд

	return true;
}

void Calculator::Compute(char op) {
	bool res = false;
	double num1, num2;

	res = GetTwoOperands(num1, num2);

	if (res) {
		switch (op)
		{
		case '+': S.Push(num1 + num2);
			break;
		case '-': S.Push(num2 - num1);
			break;
		case '*': S.Push(num1 * num2);
			break;
		case '/':
			if (num1 == 0.0) {
				S.Clear();
				std::cout << "Ошибка: деление на ноль!" << std::endl;
				return;
			}
			else {
				S.Push(num2 / num1);
				break;
			}
		}
	} else
		S.Clear();
}

Calculator::Calculator() {

}

void Calculator::Run(void) {
	char c;
	double newoperand;
	std::cout << "Введите выражение: ";
	while (std::cin >> c, c != '=') // читать до символа '=' (Выход)
	{
		switch (c)
		{
		case '+': // определение нужного оператора
		case '-':
		case '*':
		case '/':
			Compute(c); // имеется оператор; вычислить его
			break;
		default:
			//не оператор, возможно, операнд; вернуть символ
			std::cin.putback(c);
			// читать операнд и передавать его в стек
			std::cin >> newoperand;
			AddTop(newoperand);
			break;
		}
	}
	// ответ, сохраняемый в вершине стека печатать с использованием Peek
	if (!S.isEmpty())
		std::cout << S.Peek() << std::endl;

}

void Calculator::Clear(void) {
	S.Clear();
}