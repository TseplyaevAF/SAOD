#include "Search.h"
#include <random>
#include <iostream>

void init_array(int* array, int n, int min, int max) {
	for (int i = 0; i < n; i++) {
		array[i] = min + rand() % max;
	}
}

void init_array(int* array, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "Введите " << i+1 << " элемент : ";
		std::cin >> array[i];
	}
}

void show_array(int* array, int n) {
	for (size_t i = 0; i < n; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}