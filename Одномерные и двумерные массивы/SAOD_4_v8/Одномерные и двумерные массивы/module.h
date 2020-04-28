#pragma once
#include <fstream>

struct Point {
	int x;
	int y;
};

//  иницализация n точек в пределе от low до high
void init_dots(Point *point, int low, int high, int n); 

// вывод координат точек в файл
void write_dots_file(Point *point, int n, std::ofstream &f);

// функция выбора точек
// res1, res2 - переменные для записи результата
// r - радиус круга
void choice_dots(Point* point, int& res1, int& res2, int r, int n, std::ofstream& f);