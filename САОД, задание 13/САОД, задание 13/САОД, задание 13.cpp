#include <iostream>
#include <iomanip> 
#include "calc_F.h"

using namespace std;

int main()
{
	setlocale(0, "RUS");
	float a, b, c, x, x_n, dx;
	cout << "Введите a, b, c: ";
	cin >> a >> b >> c;
	cout << endl;
	
	do 
	{
		cout << "Введите x-начальное и x-конечное: ";
		cin >> x >> x_n;
	} while (x > x_n); // проверка на некорректный ввод

	do {
		cout << "Введите шаг dx > 0: ";
		cin >> dx;
	} while (dx < 0); // проверка на некорректный ввод

	// проверка выражения
	if (expression1(a, b, c) == 0) to_int(a, b, c);
	cout.precision(6);
	do {
		// каждая итерация цикла - расчет нового значения F
		// и вывод его в консоль
		cout << "F(" << x << ") = " << "\t"  <<
			F1(a, b, c, x, x_n, dx) << endl;
		x += dx;
	} while (x <= x_n);

	system("pause");
	return 0;
}
