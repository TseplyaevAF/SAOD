#include "Calculator.h"
#include <iostream>

void Calculator::AddTop(double num) {
	S.Push(num);
}

bool Calculator::GetTwoOperands(double& opndl, double& opnd2) {
	if (S.isEmpty()) // ��������� ������� ������� ��������
	{
		std::cout << "����������� ������� 1!";
		return false;
	}
	opndl = S.Pop(); // ������� ������ �������

	if (S.isEmpty()) // ��������� ������� ������� �������� 
	{
		std::cout << "����������� ������� 2!";
		return false;
	}
	opnd2 = S.Pop(); // ������� ����� �������

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
				std::cout << "������: ������� �� ����!" << std::endl;
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
	std::cout << "������� ���������: ";
	while (std::cin >> c, c != '=') // ������ �� ������� '=' (�����)
	{
		switch (c)
		{
		case '+': // ����������� ������� ���������
		case '-':
		case '*':
		case '/':
			Compute(c); // ������� ��������; ��������� ���
			break;
		default:
			//�� ��������, ��������, �������; ������� ������
			std::cin.putback(c);
			// ������ ������� � ���������� ��� � ����
			std::cin >> newoperand;
			AddTop(newoperand);
			break;
		}
	}
	// �����, ����������� � ������� ����� �������� � �������������� Peek
	if (!S.isEmpty())
		std::cout << S.Peek() << std::endl;

}

void Calculator::Clear(void) {
	S.Clear();
}