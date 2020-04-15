#include <iostream>
#include "functions.h"
#include <ctime>

using namespace std;

int main()
{
	setlocale(0, "RUS");
	unsigned N;

	cout << "Введите N: ";
	cin >> N;
	cout << "\n--------------------------------------------------\n";

	cout << "Первые " << N << " чисел Фибоначчи, вычисленные реурсивно: \n\n";
	unsigned int start_time = clock();
	for (unsigned i = 0; i < N; i++)
	{
		cout << Fib_Rec(i) << " ";
	}
	unsigned int end_time = clock();
	cout << "\n\n";

	cout << "Скорость выполнения 1 функции: " <<
		(double)(end_time - start_time) / CLOCKS_PER_SEC << " c\n";
	cout << "\n--------------------------------------------------\n\n";

	cout << "Первые " << N << " чисел Фибоначчи, вычисленные итеративно: \n\n";
	start_time = clock();
	for (unsigned i = 1; i < N + 1; i++)
	{
		cout << Fib_It(i) << " ";
	}
	end_time = clock();
	cout << "\n\n";

	cout << "Скорость выполнения 2 функции: " <<
		(double)(end_time - start_time) / CLOCKS_PER_SEC << " c\n";
	cout << "\n--------------------------------------------------\n\n";

	system("pause");
	return 0;
}