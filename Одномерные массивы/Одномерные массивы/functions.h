#pragma once
#include <string>

// Создание динамического массива вручную
float* create_array(unsigned n);

// Создание динамического массива рандомно
float* create_array(unsigned n, int min_limit, int max_limit);

// Запись массива в файл
void array2file(float* a, std::ofstream& f, unsigned n);

// Поиск номера минимального элемента
unsigned short search_min(float* a, unsigned n);

// Вычисление суммы элементов массива, 
// расположенных между первым и вторым отрицательными элементами
float sum_elements(float *a, unsigned n);

// Сортировка элементов. Сначала элементы модуль которых < 1, потом все остальные
void sort_array(float *a, unsigned n);

// Запись результатов в файл варианта 8
void write2text(float* a, std::ofstream& f, unsigned n, unsigned min, float sum);

// Кол-во элементов в диапазоне от A до B
unsigned count_elements(float *a, unsigned n, int A, int B);

// Сумма элементов после max
float sum_elements_var13(float* a, unsigned n);

// Сортировка элементов по убыванию модулей
void sort_array_var13(float* a, unsigned n);

// Запись результатов в файл варианта 13
void write2text_var13(float* a, std::ofstream& f, unsigned n, float sum);