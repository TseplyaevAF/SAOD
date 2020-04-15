#include <iostream>
#include <fstream>
#include "functions.h"
#include <math.h>
#include <ctime>

//создание массива
float* create_array(unsigned n) {
	float* a = new float[n];
	for (unsigned i = 0; i < n; i++) {
		std::cout << "a[" << i + 1 << "] = ";
		std::cin >> a[i];
	}
	return a;
}

// Создание динамического массива рандомно
float* create_array(unsigned n, int min_limit, int max_limit) {
	float* a = new float[n];
	srand(time(NULL));
	for (unsigned i = 0; i < n; i++)
		a[i] = 0.1*(rand() % (max_limit - min_limit + 1) + min_limit);
	return a;
}

//запись массива в файл
void array2file(float* a, std::ofstream& f, unsigned n) {
	for (unsigned i = 0; i < n; i++) {
		f << "a[" << i + 1 << "] = " << a[i] << std::endl;
	}
	f << std::endl;
}

// Поиск номера минимального элемента
unsigned short search_min(float* a, unsigned n) {
	unsigned short index_min = 0;
	float min = a[0];

	for (unsigned i = 1; i < n; i++)
	{
		if (a[i] < min) {
			min = a[i];
			index_min = i;
		}
	}
	return index_min;
}

float sum_elements(float* a, unsigned n) {
	int i_firstNegativeEl = 0; // индекс первого отрицательного элемента
	int i_secondNegativeEl = 0; // индекс второго отрицательного элемента
	bool flag = false, flag2 = false;
	float sum = 0;

	// нахождение i_firstNegativeEL
	for (unsigned i = 0; i < n; i++)
	{
		if (a[i] < 0) {
			i_firstNegativeEl = i;
			flag = true;
			break;
		}
	}

	// отрицательных элементов нет, возвращаем 0
	if (!flag) return 0; 

	// нахождение i_secondNegativeEl
	for (unsigned i = i_firstNegativeEl+1; i < n; i++)
	{
		if (a[i] < 0) {
			i_secondNegativeEl = i;
			flag2 = true;
			// сложение элементов
			for (unsigned j = i_firstNegativeEl+1; j < i_secondNegativeEl; j++)
				sum += a[j];
			break;
		}
	}

	if (!flag2) return 0;

	return sum;
}

void sort_array(float* a, unsigned n) {
	unsigned i_buf = 0; 
	float tmp = 0;
	for (unsigned i = 0; i < n-1; i++)
	{
		i_buf = i;
		for (unsigned j = i+1; j < n; j++)
			if (abs(a[j]) < 1) i_buf = j;

		if (i_buf != i) {
			tmp = a[i];
			a[i] = a[i_buf];
			a[i_buf] = tmp;
		}
	}
}

// Запись результатов в файл
void write2text(float* a, std::ofstream& f, unsigned n, unsigned min, float sum) {

	f << "Исходный массив:" << std::endl;
	array2file(a, f, n);
	f << "Номер минимального элемента: " << min + 1 << "\n\n";
	f << "Сумма элементов: " << sum << "\n\n";
	sort_array(a, n);
	f << "Массив после сортировки:" << std::endl;
	array2file(a, f, n);
}

// Вычислить кол-во элементов в диапазоне от A до B
unsigned count_elements(float* a, unsigned n, int A, int B) {
	int count = 0;
	for (unsigned i = 0; i < n; i++)
	{
		if (i >= A && i <= B) {
			count++;
		}
	}
	return count;
}

// Сумма элементов после max
float sum_elements_var13(float* a, unsigned n) {
	float max = a[0], sum = 0;
	int i_max = 0;

	for (unsigned i = 1; i < n; i++)
	{
		if (a[i] > max) {
			max = a[i];
			i_max = i;
		}
	}

	for (unsigned i = i_max + 1; i < n; i++)
		sum += a[i];

	return sum;
}

// Сортировка элементов по убыванию модулей
void sort_array_var13(float* a, unsigned n) {
	unsigned i_buf = 0;
	float tmp = 0;
	for (unsigned i = 0; i < n - 1; i++)
	{
		i_buf = i;
		for (unsigned j = i + 1; j < n; j++)
			if (abs(a[j]) > abs(a[i_buf])) i_buf = j;

		if (i_buf != i) {
			tmp = a[i];
			a[i] = a[i_buf];
			a[i_buf] = tmp;
		}
	}
}

// Запись результатов в файл варианта 13
void write2text_var13(float* a, std::ofstream& f, unsigned n, float sum) {
	f << "Исходный массив:" << std::endl;
	array2file(a, f, n);
	f << "Сумма элементов: " << sum << "\n\n";
	sort_array_var13(a, n);
	f << "Массив после сортировки:" << std::endl;
	array2file(a, f, n);
}