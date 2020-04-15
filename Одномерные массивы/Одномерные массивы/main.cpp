#include <iostream>
#include "functions.h"
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(0, "RUS");
	const unsigned n = 1000;
	float* a;
	ofstream f;
	unsigned variant;
	//{ 1.5, 24, -0.8, 1, 0.2, 4.3, -6, 5, -7, 0 };
	cout << "Введите номер варианта: ";
	cin >> variant;

	if (variant == 8) {
		unsigned int start_time = clock(); // начальное время
		a = create_array(n, -1000, 1000); // создание динамического массива
		unsigned int end_time = clock(); // конечное время
		cout << "Скорость выполнения функции create_array: " << (double)(end_time - start_time) / CLOCKS_PER_SEC<< endl;
		f.open("САОД, задание 8.txt", ios_base::out);
		unsigned short index_min = search_min(a, n);
		float sum = sum_elements(a, n);
		start_time = clock();
		write2text(a, f, n, index_min, sum);
		end_time = clock();
		cout << "Скорость выполнения функции write2text: " << (double)(end_time - start_time) / CLOCKS_PER_SEC <<" c" << endl;
		delete[] a; // очищение памяти
		f.close();
	} else
		if (variant == 13) {
			a = create_array(n,-10000, 10000); // создание динамического массива
			f.open("САОД, задание 13.txt", ios_base::out);
			unsigned A = 1, B = 4;
			unsigned count = count_elements(a, n, A, B);
			f << "Количество элементов на промежутке от " << A << " до " << B << ": "
				<< count << "\n\n";
			float sum = sum_elements_var13(a, n);
			unsigned int start_time = clock(); // начальное время
			write2text_var13(a, f, n, sum);
			unsigned int end_time = clock(); // конечное время
			cout << "Скорость выполнения функции write2text: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " c" << endl;
			delete[] a; // очищение памяти
			f.close();
		}
		else
			cout << "Такого варианта нет" << endl;
	
	system("pause");
	return 0;
}
