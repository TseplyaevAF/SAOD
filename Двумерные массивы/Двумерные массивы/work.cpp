#include "work.h"
#include <ctime>
#include <random>
#include <iostream>

vector_int create_vector(unsigned n, unsigned m, int min_limit, int max_limit) {
	std::vector<std::vector <int>> v;

	srand(time(NULL));
	v.resize(n);// n строк
	for (unsigned i = 0; i < v.size(); i++)
		v[i].resize(m);// m элементов

	for (unsigned i = 0; i < v.size(); i++)
		for (unsigned j = 0; j < v[i].size(); j++)
			v[i][j] = rand() % (max_limit - min_limit + 1) + min_limit;

	return v;
}

// создание матрицы и заполнение вручную
vector_int create_vector(unsigned n, unsigned m) {
	std::vector<std::vector <int>> v;

	srand(time(NULL));
	v.resize(n);// n строк
	for (unsigned i = 0; i < v.size(); i++)
		v[i].resize(m);// m элементов

	for (unsigned i = 0; i < v.size(); i++) {
		for (unsigned j = 0; j < v[i].size(); j++) {
			std::cout << "a[" << i << "]" << "[" << j << "]" << " = ";
			std::cin >> v[i][j];
		}
		std::cout << std::endl;
	}
	return v;
}

//запись матрицы в файл
void matrix2file(vector_int a, std::ofstream& f) {
	for (unsigned i = 0; i < a.size(); i++) {
		for (unsigned j = 0; j < a[i].size(); j++) {
			f << a[i][j] << "\t";
		}
		f << std::endl;
	}
	f << std::endl;
}

// Задание 8, характеристики столбцов
vector_int characteristic_column_var8(vector_int a, std::ofstream& f) {
	// массив для хранения сумм элементов
	std::vector <int> sum;
	sum.resize(a[0].size());
	bool flag = false;

	// поиск отрцицательных нечетных элементов для суммирования их модулей
	for (int i = 0; i < a[0].size(); i++)
	{
		sum[i] = 0;
		for (int j = 0; j < a.size(); j++)
		{
			if ((a[j][i] < 0) && (a[j][i] % 2 != 0))
				sum[i] += abs(a[j][i]);
		}
	}
	
	f << "Массив характеристик столбцов: " << std::endl;
	for (int i = 0; i < sum.size(); i++)
	{
		f << sum[i] << "  ";
	}
	f << "\n\n";

	int min, i_min;
	for (int i = 0; i < a[0].size() - 1; i++) {
		min = sum[i];
		i_min = i;
		for (int j = i + 1; j < a[0].size(); j++) {
			if (sum[j] < min) {
				min = sum[j];
				i_min = j;
			}
		}
		if (i_min != i) {
			swap(sum[i], sum[i_min]);
			for (int i_new = 0; i_new < a.size(); i_new++)
			{
				swap(a[i_new][i], a[i_new][i_min]);
			}
		}
	}
	f << "Отсортированная матрица по возрастанию характеристик: " << std::endl;
	matrix2file(a, f);

	return a;
}

void swap(int &a, int &b) {
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void sum_elements_var8(vector_int a, std::ofstream& f) {
	// массив для хранения сумм элементов
	std::vector <int> sum;
	sum.resize(a[0].size());
	for (int i = 0; i < a[0].size(); i++)
	{
		sum[i] = 0;
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j][i] < 0) {
				for (int k = 0; k < a.size(); k++)
				{
					sum[i] += a[k][i];
				}
				break;
			}
		}
	}

	f << "Сумма элементов: " << std::endl;
	for (int i = 0; i < sum.size(); i++)
	{
		f << sum[i] << " ";
	}
	f << "\n\n";
}

// Задание 13, циклический сдвиг вправо
void cyclic_shift_right(vector_int a, unsigned count, std::ofstream& f) {
	int buf; // переменная для записи последнего элемента
	int index = 0;
	while (count != 0) {
		for (int i = 0; i < a.size(); i++) {
			buf = a[i][a.size() - 1];
			for (int j = a.size() - 2; j >= 0; j--)
			{
				a[i][j + 1] = a[i][j];
			}
			a[index][0] = buf;
			index++;
		}
		count--;
		index = 0;
	}
	matrix2file(a, f);
}

// Задание 13, циклический сдвиг вниз
void cyclic_shift_down(vector_int a, unsigned count, std::ofstream& f) {
	int buf; // переменная для записи последнего элемента
	int index = 0;
	while (count != 0) {
		for (int i = 0; i < a.size(); i++) {
			buf = a[a.size() - 1][i];
			for (int j = a.size() - 2; j >= 0; j--)
			{
				a[j+1][i] = a[j][i];
			}
			a[0][index] = buf;
			index++;
		}
		count--;
		index = 0;
	}
	matrix2file(a, f);
}