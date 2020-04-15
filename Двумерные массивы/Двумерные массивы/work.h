#pragma once
#include <vector>
#include <fstream>

using vector_int = std::vector<std::vector<int>>;

// создание матрицы и заполнение случайными числами от min_limit до max_limit
vector_int create_vector(unsigned n, unsigned m, int min_limit, int max_limit);

// создание матрицы и заполнение вручную
vector_int create_vector(unsigned n, unsigned m);

//запись матрицы в файл
void matrix2file(vector_int a, std::ofstream& f);


// Задание 8, характеристики столбцов
vector_int characteristic_column_var8(vector_int a, std::ofstream& f);

// Задание 8, сумма элементов
void sum_elements_var8(vector_int a, std::ofstream& f);

// Функция обмена значениями
void swap(int &a, int &b);

// Задание 13, циклический сдвиг вправо
void cyclic_shift_right(vector_int a, unsigned count, std::ofstream& f);

// Задание 13, циклический сдвиг вниз
void cyclic_shift_down(vector_int a, unsigned count, std::ofstream& f);