#pragma once

// Шаблонная функция линейного поиска элементов в массиве по ключу
// Вернет индекс найденного элемента
template <class T>
int linear_search(T* arr, int n, int start, T key) {

	for (int i = start; i < n; i++)
	{
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

// Шаблонная функция бинарного поиска элементов в массиве по ключу
// Вернет индекс найденного элемента
template <class T>
int binary_search(T* arr, int n, T key) {
	int left = 0; // задаем левую и правую границы поиска
	int right = n-1;
	//std::vector<int> vec = {-1};
	while (left <= right) // пока левая граница не "перескочит" правую
	{
		int mid = (left + right) / 2; // ищем середину отрезка
		if (key == arr[mid]) {  // если ключевое поле равно искомому
			return mid; // мы нашли требуемый элемент
		}
		if (key < arr[mid])     // если искомое ключевое поле меньше найденной середины
			right = mid - 1;  // смещаем правую границу, продолжим поиск в левой части
		else                  // иначе
			left = mid + 1;   // смещаем левую границу, продолжим поиск в правой части
	}
	return -1;
}

// Заполнение массива случайными числами
void init_array(int* array, int n, int min, int max);

// Заполнение массива вручную
void init_array(int* array, int n);

// Вывод массива в консоль
void show_array(int* array, int n);