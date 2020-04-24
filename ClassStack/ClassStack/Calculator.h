#pragma once
#include "Stack.h"

class Calculator 
{
	private:
		Stack<double> S;

		void AddTop(double num);
		bool GetTwoOperands(double &sopndl, double &sopnd2);
		void Compute(char op);

	public:
		// �����������
		Calculator();
		// ��������� ��������� � �������� �����������
		void Run(void);
		void Clear(void);

};
